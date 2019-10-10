#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/mman.h>

#include "libc-deps.h"

#define CHUNK_SIZE (0x4000)

#define ERROR_CORRUPT() \
    corrupted(__FILE__, __func__, __LINE__)

#define LESSER(x, y) ((x) < (y) ? (x) : (y))

struct malloc_chunk {
    size_t sum;
    void *start, *cur;
    size_t size;
    struct malloc_chunk *prev;
    struct malloc_chunk *next;
};

struct allocation_info {
    size_t sum;
    void *start;
    size_t size, free;
    struct allocation_info *prev;
    struct allocation_info *next;
};

static size_t alloc_cnt;
static struct malloc_chunk *malloc_chunk;
static struct allocation_info *allocation_info;

static void corrupted(const char *file, const char *func, int line)
{
    fprintf(stderr,
            "*** %s: %s:%u: %s: double free or corruption\n",
            __progname,
            file,
            line,
            func);
    abort();
}

/* Allocate and initialize next chunk */
static int get_next_chunk(size_t size)
{
    struct malloc_chunk *mallchunk = __mmap(NULL,
                                            size + sizeof(*mallchunk),
                                            PROT_READ | PROT_WRITE,
                                            MAP_PRIVATE | MAP_ANONYMOUS,
                                            -1,
                                            0);

    if(mallchunk == MAP_FAILED)
    {
        /* Fall back to sbrk(). */
        mallchunk = __sbrk(size + sizeof(*mallchunk));
        if(mallchunk == (void *)-1)
            /* Now we fail. */
            return -1;
    }

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

    malloc_chunk->start = malloc_chunk + 1;
    malloc_chunk->size = size;

    return 0;
}

/* Create new allocation of size `size` and alignment `align` */
static int get_next_allocation(size_t size, int align)
{
    size_t ctr,
           chunk_size,
           alloc_size;
    int found_allocation = 0, rem;
    struct allocation_info *tmp_alloc;

    /* Round up to nearest multiple of pointer size */
    if((rem = size % align))
    {
        if(size > SIZE_MAX - align)
            return -1;
        size += align - rem;
    }

    alloc_size = size + sizeof(struct allocation_info);
    chunk_size = alloc_size > CHUNK_SIZE ? alloc_size : CHUNK_SIZE;

    if(!malloc_chunk)
        if(get_next_chunk(chunk_size) == -1)
            return -1;

    if(!allocation_info) /* First allocation */
    {
        allocation_info = malloc_chunk->start;
        allocation_info->start = allocation_info + 1;
        malloc_chunk->cur = (char *)allocation_info->start + size;
        allocation_info->next = allocation_info->prev = NULL;
        goto set_size;
    }

    tmp_alloc = allocation_info;

    /* Rewind to initial allocation and go on from there */
    while(tmp_alloc->prev)
        tmp_alloc = tmp_alloc->prev;

    /* Check if suitable allocation has already been made,
     * and if the memory has been freed. If so, use it instead.
     */
    for(ctr = 0;
        (ctr < alloc_cnt) && tmp_alloc;
        ctr++, tmp_alloc = tmp_alloc->next)
    {
        if(tmp_alloc->free)
        {
            if(tmp_alloc->size >= size)
            {
                /* We found a suitable allocation.
                 * Now unlink it from the list, and exit the loop.
                 */
                found_allocation = 1;
                if(tmp_alloc->prev)
                    tmp_alloc->prev->next = tmp_alloc->next;
                if(tmp_alloc->next)
                    tmp_alloc->next->prev = tmp_alloc->prev;
                tmp_alloc->next = NULL;
                break;
            }
            else if(!tmp_alloc->next)
            {
                /* We found an allocation that we can expand. */
                /* TODO: complete this */
            }
        }
    }

    if(!found_allocation)
    {
        if(((char *)malloc_chunk->start + malloc_chunk->size)
            - (char *)malloc_chunk->cur
                >= (ptrdiff_t)(malloc_chunk->size - alloc_size))
        {
            /* We don't have enough space left in the chunk */
            if(get_next_chunk(chunk_size) == -1)
                return -1;
            tmp_alloc = malloc_chunk->start;
        }
        else
        {
            tmp_alloc = malloc_chunk->cur;
        }

        tmp_alloc->start = tmp_alloc + 1;
        malloc_chunk->cur = (char *)tmp_alloc->start + size;
        tmp_alloc->next = NULL;
    }
    allocation_info->next = tmp_alloc;
    allocation_info->next->prev = allocation_info;
    allocation_info = allocation_info->next;
set_size:
    allocation_info->size = size;
    allocation_info->free = 0;
    alloc_cnt++;
    return 0;
}

void *malloc(size_t size)
{
    if(get_next_allocation(size, sizeof(max_align_t)) == -1)
        return NULL;
    return allocation_info->start;
}

void *realloc(void *ptr, size_t size)
{
    size_t newsize;
    void *newptr = malloc(size);

    struct allocation_info *allinfo = allocation_info;

    if(!ptr)
        goto end;

    while(allinfo->prev)
    {
        allinfo = allinfo->prev;
    }

    while(allinfo->next && allinfo->start != ptr)
    {
        allinfo = allinfo->next;
    }

    if(!allinfo->next)
        ERROR_CORRUPT();

    newsize = LESSER(allinfo->size, size);

    memcpy(newptr, ptr, newsize);

end:
    free(ptr);
    return newptr;
}

void free(void *ptr)
{
    struct allocation_info *allinfo = allocation_info;

    if(!ptr)
        return;

    while(allinfo->prev)
    {
        allinfo = allinfo->prev;
    }

    while(allinfo && allinfo->start != ptr)
    {
        allinfo = allinfo->next;
    }

    if(!allinfo || allinfo->free)
    {
        ERROR_CORRUPT();
    }

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

    if(ret)
        memset(ret, 0, total_size);

    return ret;
}
