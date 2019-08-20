#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/mman.h>
#include <stdnoreturn.h>

#define CHUNK_SIZE (0x4000)
/* Just some random value I pulled off an RNG */
#define MAGIC_NUMBER 1396583176

/* Validate magic number and error if it's incorrect */
#define CHECK_CORRUPTION(x) \
    do { \
        if((x)->magic_number != MAGIC_NUMBER) \
            corrupted((void *)(x), __LINE__, __func__); \
    } while(0)

#define ERROR_CORRUPT(x) \
    corrupted((void *)(x), __LINE__, __func__)

#define LESSER(x, y) ((x) < (y) ? (x) : (y))

#if defined(__GNUC__) && __GNUC__ >= 5
# define mul_overflow(a, b, z) __builtin_mul_overflow(a, b, &z)
#else
# define mul_overflow(a, b, z) \
({ \
    (z) = (a) * (b); \
    ((a) != 0 && ((z) / (a)) != (b)); \
})
#endif

struct malloc_chunk
{
    unsigned long magic_number;
    void *start;
    void *cur;
    size_t size;
    struct malloc_chunk *prev;
    struct malloc_chunk *next;
};

struct allocation_info
{
    unsigned int magic_number, free;
    void *start;
    size_t size;
    struct allocation_info *prev;
    struct allocation_info *next;
};

static size_t alloc_cnt;
static struct malloc_chunk *malloc_chunk;
static struct allocation_info *allocation_info;

static _Noreturn void corrupted(void *ptr, unsigned int line, const char *func)
{
	fprintf(stderr, "*** ERROR: double free or corruption at address %p\n", ptr);
	fprintf(stderr, " in function %s line %u\n", func, line);
	abort();
}

/* Allocate and initialize next chunk */
static int get_next_chunk(size_t size)
{
    struct malloc_chunk *mallchunk =
            (struct malloc_chunk *)mmap(NULL,
                   size + sizeof(*mallchunk),
                      PROT_READ | PROT_WRITE,
                  MAP_SHARED | MAP_ANONYMOUS,
                                          -1,
                                          0);
    if(mallchunk == MAP_FAILED)
        return -1;

    memset(mallchunk, 0, sizeof(*mallchunk));

    if(!malloc_chunk)
    {
        malloc_chunk = mallchunk;
    }
    else
    {
        malloc_chunk->next = mallchunk;
        malloc_chunk->next->prev = malloc_chunk;
        malloc_chunk = malloc_chunk->next;
    }

    malloc_chunk->magic_number = MAGIC_NUMBER;
    malloc_chunk->start = malloc_chunk + 1;
    malloc_chunk->size = size;

    return 0;
}

/* Create new allocation of size `size` */
static int get_next_allocation(size_t size)
{
    size_t ctr,
           chunk_size,
           alloc_size;
    int found_allocation, rem;
    struct allocation_info *tmp_alloc;

    /* Round up to nearest multiple of pointer size */
    if((rem = size % sizeof(void *)))
    {
        if(size > SIZE_MAX - sizeof(void *))
            return -1;
        size += sizeof(void *) - rem;
    }

    alloc_size = size + sizeof(struct allocation_info);
    chunk_size = alloc_size > CHUNK_SIZE ? alloc_size : CHUNK_SIZE;

    if(!malloc_chunk)
        if(get_next_chunk(chunk_size) == -1)
            return -1;

    CHECK_CORRUPTION(malloc_chunk);

    if(!allocation_info) /* First allocation */
    {
        allocation_info = (struct allocation_info *)malloc_chunk->start;
        allocation_info->magic_number = MAGIC_NUMBER;
        allocation_info->start = allocation_info+1;
        malloc_chunk->cur = allocation_info->start + size;
        allocation_info->next = allocation_info->prev = NULL;
        goto set_size;
    }

    tmp_alloc = allocation_info;

    /* Rewind to initial allocation and go on from there */
    while(tmp_alloc->prev)
    {
        CHECK_CORRUPTION(tmp_alloc);
        tmp_alloc = tmp_alloc->prev;
    }

    /* Check if suitable allocation has already been made,
     * and if the memory has been freed. If so, use it instead.
     */
    for(ctr = 0;
        (ctr < alloc_cnt) && tmp_alloc->next;
        ctr++, tmp_alloc = tmp_alloc->next)
    {
        CHECK_CORRUPTION(tmp_alloc);
        if( tmp_alloc->free &&
            tmp_alloc->size >= size )
        {
            /* We found a suitable allocation.
             * Now unlink it from the list, and exit the loop.
             */
            found_allocation = 1;
            if(tmp_alloc->prev) tmp_alloc->prev->next = tmp_alloc->next;
            if(tmp_alloc->next) tmp_alloc->next->prev = tmp_alloc->prev;
            tmp_alloc->next = NULL;
            break;
        }
    }

    if(!found_allocation)
    {
        if(((char *)malloc_chunk->start + malloc_chunk->size)
            - (char *)malloc_chunk->cur
                > (ptrdiff_t)(alloc_size))
        {
            /* We don't have enough space left in the chunk */
            if(get_next_chunk(chunk_size) == -1)
                return -1;
            CHECK_CORRUPTION(malloc_chunk);
            tmp_alloc = (struct allocation_info *)malloc_chunk->start;
        }
        else
        {
            tmp_alloc = (struct allocation_info *)malloc_chunk->cur;
        }

        tmp_alloc->magic_number = MAGIC_NUMBER;
        tmp_alloc->start = tmp_alloc + 1;
        malloc_chunk->cur = tmp_alloc->start + size;
        tmp_alloc->next = NULL;
    }
    allocation_info->next = tmp_alloc;
    allocation_info->next->prev = allocation_info;
    allocation_info = allocation_info->next;
set_size:
    CHECK_CORRUPTION(allocation_info);
    allocation_info->size = size;
    allocation_info->free = 0;
    alloc_cnt++;
    return 0;
}

void *malloc(size_t size)
{
    if(get_next_allocation(size) == -1)
        return NULL;
    return allocation_info->start;
}

void *realloc(void *ptr, size_t size)
{
    size_t newsize = 0;
    void *newptr = malloc(size);

    struct allocation_info *allinfo = allocation_info;

    if(!ptr) goto end;

    while(allinfo->prev)
    {
        CHECK_CORRUPTION(allinfo);
        allinfo = allinfo->prev;
    }

    while(allinfo->next && allinfo->start != ptr)
    {
        CHECK_CORRUPTION(allinfo);
        allinfo = allinfo->next;
    }

    if(!allinfo->next) ERROR_CORRUPT(ptr);

    newsize = LESSER(allinfo->size, size);

    memcpy(newptr, ptr, newsize);

end:
    free(ptr);
    return newptr;
}

void free(void *ptr)
{
    struct allocation_info *allinfo = allocation_info;

    if(!ptr) return;

    while(allinfo->prev)
    {
        CHECK_CORRUPTION(allinfo);
        allinfo = allinfo->prev;
    }

    while(allinfo->next && allinfo->start != ptr)
    {
        CHECK_CORRUPTION(allinfo);
        allinfo = allinfo->next;
    }

    if(!allinfo->next || allinfo->free) ERROR_CORRUPT(ptr);

    memset(allinfo->start, 0, allinfo->size);
    allinfo->free = 1;
}

void *calloc(size_t nmemb, size_t size)
{
    size_t total_size;
    void *ret;

    if(mul_overflow(size, nmemb, total_size))
    {
        errno = ENOMEM;
        return NULL;
    }

    ret = malloc(total_size);

    if(ret) memset(ret, 0, total_size);
    return ret;
}
