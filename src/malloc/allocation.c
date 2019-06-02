/*
 *  Copyright (C) 2019 James Larrowe
 *
 *  This file is part of Minilibc.
 *
 *  Minilibc is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Minilibc is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Minilibc.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <unistd.h>
#include <stddef.h>
#include <sys/mman.h>

#include "malloc.h"

int __get_next_allocation(size_t size)
{
    size_t ctr = 0;
    int found_allocation = 0;
    struct allocation_info *tmp_alloc = NULL;
    struct malloc_chunk *tmp_chnk = NULL;

    if(!__mallchunk)
        if(__get_next_chunk())
            return -1;

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
            if(__get_next_chunk())
                return -1;
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
    return 0;
}
