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

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "malloc.h"

int __get_next_chunk(void)
{
    struct malloc_chunk *mallchunk = mmap(NULL,
                                    CHUNK_SIZE,
                        PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS,
                                            -1,
                                            0);
    if(mallchunk == MAP_FAILED)
    {
        errno = ENOMEM;
        return -1;
    }

    if (!__mallchunk)
    {
        __mallchunk = mallchunk;
        __mallchunk->chunk_cnt = 0;
        __mallchunk->alloc_cnt = 0;
        __mallchunk->prev = NULL;
        __mallchunk->next = NULL;
    }
    else
    {
        __mallchunk->chunk_cnt++;
        __mallchunk->next = mallchunk;
        __mallchunk->next->chunk_cnt =
                __mallchunk->chunk_cnt;
        __mallchunk->next->prev = __mallchunk;
        __mallchunk = __mallchunk->next;
        __mallchunk->alloc_cnt = 0;
        __mallchunk->next = NULL;
    }

    __mallchunk->start = (void *)__mallchunk +
                        sizeof(*__mallchunk);
    return 0;
}
