#include <unistd.h>
#include <stddef.h>
#include <sys/mman.h>

#include "malloc.h"

void __get_next_allocation(size_t size)
{
    size_t ctr = 0;
    int found_allocation = 0;
    struct allocation_info *tmp_alloc = NULL;
    struct malloc_chunk *tmp_chnk = NULL;

    if(!__mallchunk)
        __get_next_chunk();

    if(!__allocinfo)
        __allocinfo = __mallchunk->start;

    tmp_alloc = __allocinfo;
    tmp_chnk = __mallchunk;

    while(tmp_chnk->prev != NULL)
        tmp_chnk = tmp_chnk->prev;

    for(ctr = 0;
        ctr < tmp_chnk->alloc_cnt && tmp_alloc;
        ctr++, tmp_alloc = tmp_alloc->next)
    {
        if( tmp_alloc->free &&
            tmp_alloc->size >= size )
        {
            found_allocation = 1;
            tmp_alloc->prev->next = tmp_alloc->next;
            tmp_alloc->next->prev = tmp_alloc->prev;
            tmp_alloc->next = NULL;
            break;
        }
    }

    if(!found_allocation)
    {
        if((size_t)(__allocinfo->start - __mallchunk->start)
                > ((CHUNK_SIZE - size) - sizeof(*tmp_alloc)))
        {
            __get_next_chunk();
            tmp_alloc = __mallchunk->start;
        }
        else
        {
            tmp_alloc = __allocinfo->start +
                        __allocinfo->size;
        }

        tmp_alloc->start = (void *)tmp_alloc
                    + sizeof(*tmp_alloc);
        tmp_alloc->next = NULL;
    }
    __allocinfo->next = tmp_alloc;
    __allocinfo->next->prev = __allocinfo;
    __allocinfo = __allocinfo->next;
    __allocinfo->size = size;
    __allocinfo->free = 0;
    __mallchunk->alloc_cnt++;
}
