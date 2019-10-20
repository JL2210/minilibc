#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/mman.h>
#include <stdnoreturn.h>

#include "libc-deps.h"

#define CHUNK_SIZE (0x4000)

#define ERROR_CORRUPT() \
    corrupted(__FILE__, __func__, __LINE__)

#define LESSER(x, y) ((x) < (y) ? (x) : (y))

struct malloc_chunk {
    size_t size;
    unsigned char *start, *cur, *end;
    struct malloc_chunk *prev;
    struct malloc_chunk *next;
};

struct allocation_info {
    size_t size;
    unsigned int free:1;
    unsigned char *start, *end;
    struct allocation_info *prev;
    struct allocation_info *next;
};

static size_t alloc_cnt;
static struct malloc_chunk *malloc_chunk;
static struct allocation_info *allocation_info;

noreturn static void corrupted(const char *file, const char *func, int line)
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

    /* clear just the chunk in case we
       forget to set one of the fields */
    memset(mallchunk, 0, sizeof(*mallchunk));

    if(!malloc_chunk)
    {
        /* First chunk, set and leave */
        malloc_chunk = mallchunk;
    }
    else
    {
        /* Add a new link to the list */
        malloc_chunk->next = mallchunk;
        malloc_chunk->next->prev = malloc_chunk;
        malloc_chunk = malloc_chunk->next;
    }

    /* Set start address to just after the info. */
    malloc_chunk->start = (void *)(malloc_chunk + 1);
    malloc_chunk->end = malloc_chunk->start + size;
    malloc_chunk->size = size;

    return 0;
}

/* Create new allocation of size `size` and alignment `align` */
static int get_next_allocation(size_t size, int align)
{
    size_t ctr,
           chunk_size,
           alloc_size;
    int found_allocation = 0;
    struct allocation_info *tmp_alloc;

    /* Check for possible UB */
    if(size >= PTRDIFF_MAX)
    {
        errno = ENOMEM;
        return -1;
    }

    /* Round up to nearest multiple of pointer size
       we don't have to worry about non-powers of
       two, but handle them anyway */
    alloc_size = size + (align - size % align) +
                 sizeof(struct allocation_info);

    chunk_size = alloc_size > CHUNK_SIZE ? alloc_size : CHUNK_SIZE;

    if(!malloc_chunk) /* First chunk */
        if(get_next_chunk(chunk_size) == -1)
            return -1;

    if(!allocation_info) /* First allocation */
    {
        allocation_info = (void *)malloc_chunk->start;
        allocation_info->start = (void *)(allocation_info + 1);
        malloc_chunk->cur =
          allocation_info->end = allocation_info->start + size;
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
                 * Now unlink it from the list and exit the loop.
                 */
                found_allocation = 1;
                if(tmp_alloc->prev)
                    tmp_alloc->prev->next = tmp_alloc->next;
                if(tmp_alloc->next)
                    tmp_alloc->next->prev = tmp_alloc->prev;
                tmp_alloc->next = NULL;
                break;
            }
            else if(tmp_alloc->end == malloc_chunk->cur &&
                      malloc_chunk->end - tmp_alloc->start >= (ptrdiff_t)size)
            {
                /* We found an allocation that we can expand. */
                found_allocation = 1;
                tmp_alloc->size = size;
                malloc_chunk->cur =
                  tmp_alloc->end = tmp_alloc->start + size;
                break;
            }
        }
    }

    if(!found_allocation)
    {
        if(alloc_size > (size_t)(malloc_chunk->end - malloc_chunk->cur))
        {
            /* We don't have enough space left in the chunk */
            if(get_next_chunk(chunk_size) == -1)
                return -1;
            tmp_alloc = (void *)malloc_chunk->start;
        }
        else
        {
            tmp_alloc = (void *)malloc_chunk->cur;
        }

        tmp_alloc->start = (void *)(tmp_alloc + 1);
        malloc_chunk->cur =
          tmp_alloc->end = tmp_alloc->start + size;
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
    /* Get a new block of memory with the
       alignment of max_align_t */
    if(get_next_allocation(size, sizeof(max_align_t)) == -1)
        return NULL;
    return allocation_info->start;
}

void *realloc(void *ptr, size_t size)
{
    struct allocation_info *allinfo = allocation_info;

    /* if ptr is NULL, return malloc'ed memory */
    if(!ptr)
        return malloc(size);


    /* rewind to the beginning of the list */
    while(allinfo->prev)
    {
        allinfo = allinfo->prev;
    }

    /* While the pointer passed is not equal to
       a pointer in the list, and if allinfo is
       not NULL, continue searching */
    while(allinfo && allinfo->start != ptr)
    {
        allinfo = allinfo->next;
    }

    /* If an invalid pointer was passed, give
       an error and abort */
    if(!allinfo)
        ERROR_CORRUPT();

    if((allinfo->end == malloc_chunk->cur &&
          (size_t)(malloc_chunk->end - allinfo->start) >= size) ||
       /* If the end of this allocation is the
          end of the used portion of the chunk
          and we have enough free memory left
          in the chunk, */
         allinfo->size >= size)
       /* or if the current size is enough to hold
          the resized data, */
    {
        /* then we do not need to allocate more memory. */
        if(allinfo->size < size)
        {
            /* expand this by resizing */
            allinfo->size = size;
            malloc_chunk->cur =
              allinfo->end = allinfo->start + size;
        }
        return allinfo->start;
    }
    else
    {
        /* Allocate a new block of memory and copy
           the contents over */
        void *newptr;
        newptr = malloc(size);
        memcpy(newptr, ptr, LESSER(allinfo->size, size));
        free(ptr);
        return newptr;
    }
}

void free(void *ptr)
{
    struct allocation_info *allinfo = allocation_info;

    /* Check for a NULL pointer */
    if(!ptr)
        return;

    /* Rewind to the beginning of the list */
    while(allinfo->prev)
    {
        allinfo = allinfo->prev;
    }

    /* Search for the pointer */
    while(allinfo && allinfo->start != ptr)
    {
        allinfo = allinfo->next;
    }

    /* If the pointer was not found or
       if it has already been freed, give
       an error and abort */
    if(!allinfo || allinfo->free)
    {
        ERROR_CORRUPT();
    }

    /* zero out the memory to discourage use-
       after-free */
    memset(allinfo->start, 0, allinfo->size);

    /* Set the allocation to freed */
    allinfo->free = 1;
}

void *calloc(size_t nmemb, size_t size)
{
    size_t total_size;
    void *ret;

    /* Multiply the two arguments together
       while checking for overflow */
    if(mul_overflow(size, nmemb, total_size))
    {
        /* Whoops, overflow. Set errno to
           ENOMEM and return error */
        errno = ENOMEM;
        return NULL;
    }

    /* Allocate memory */
    ret = malloc(total_size);

    if(ret)
        /* If the allocation didn't fail,
           clear the allocated memory */
        memset(ret, 0, total_size);

    /* and return either the cleared block
       of memory or a NULL pointer */
    return ret;
}
