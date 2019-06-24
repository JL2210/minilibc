#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/mman.h>

#include "malloc.h"

int __get_next_allocation(size_t size)
{
    size_t msize,
/*
           ctr = 0,
 */
           chunk_size;
    char found_allocation = 0;
    ainfo *tmp_alloc = NULL;
/*
    mchunk *tmp_chnk = NULL;
 */

    if(size % sizeof(void *))
    {
        if(size > SIZE_MAX - sizeof(void *))
            return -1;
        size += sizeof(void *) - (size % sizeof(void *));
    }

    msize = size +
            sizeof(mchunk) +
            sizeof(ainfo);
    chunk_size = msize > CHUNK_SIZE ? msize : CHUNK_SIZE;

    if(!__malloc_chunk)
        if(__get_next_chunk(chunk_size))
            return -1;

    if(!__allocation_info)
    {
        __allocation_info = (ainfo *)__malloc_chunk->start;
        __allocation_info->start = __allocation_info+1;
        __allocation_info->next = __allocation_info->prev = NULL;
        goto set_size;
    }

    tmp_alloc = __allocation_info;
/*
    tmp_chnk = __malloc_chunk;

    while(tmp_chnk->prev)
        tmp_chnk = tmp_chnk->prev;
 */
    while(tmp_alloc->prev)
        tmp_alloc = tmp_alloc->prev;

/*
    for(ctr = 0;
        (ctr < tmp_chnk->alloc_cnt) && tmp_alloc->next;
        ctr++, tmp_alloc = tmp_alloc->next)
    {
        if( tmp_alloc->free &&
            tmp_alloc->size == size )
        {
            found_allocation = 1;
            if(tmp_alloc->prev) tmp_alloc->prev->next = tmp_alloc->next;
            if(tmp_alloc->next) tmp_alloc->next->prev = tmp_alloc->prev;
            tmp_alloc->next = NULL;
            *//* FIXME: TODO: Fix this so it doesn't overwrite the next allocation *//*
            break;
        }
    }
 */

    if(!found_allocation)
    {
        if((char *)__allocation_info->start - (char *)__malloc_chunk->start
                > (ptrdiff_t)(chunk_size - size - sizeof(*tmp_alloc)))
        {
            if(__get_next_chunk(chunk_size))
                return -1;
            tmp_alloc = (ainfo *)__malloc_chunk->start;
        }
        else
        {
            tmp_alloc = (ainfo *)((char *)__allocation_info->start +
                        __allocation_info->size);
        }

        tmp_alloc->start = tmp_alloc + 1;
        tmp_alloc->next = NULL;
    }
    __allocation_info->next = tmp_alloc;
    __allocation_info->next->prev = __allocation_info;
    __allocation_info = __allocation_info->next;
set_size:
    __allocation_info->size = size;
    __allocation_info->free = 0;
    __malloc_chunk->alloc_cnt++;
    return 0;
}
