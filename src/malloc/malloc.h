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

#ifndef _MALLOC_H
#define _MALLOC_H 1

#include <features.h>
#include <sys/types.h>

#ifdef __PTR16__
# define CHUNK_SIZE (0x4000) /* 16K */
#else
# define CHUNK_SIZE (0x10000) /* 64K */
#endif

struct malloc_chunk
{
    void *start;
    size_t alloc_cnt;
    size_t chunk_cnt;
    struct malloc_chunk *prev;
    struct malloc_chunk *next;
};

struct allocation_info
{
    void *start;
    size_t size;
    int free;
    struct allocation_info *prev;
    struct allocation_info *next;
};

extern struct malloc_chunk *__mallchunk;
extern struct allocation_info *__allocinfo;

extern int __get_next_chunk(void);
extern int __get_next_allocation(size_t size);

#endif
