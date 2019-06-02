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

#include "malloc.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define LESSER(x,y) ((x) > (y) ? (y) : (x))

void *realloc(void *ptr, size_t size)
{
    size_t newsize = 0;
    void *newptr = malloc(size);

    struct allocation_info *tmp_allinfo = __allocinfo;

    if(!ptr) return newptr;

    while(tmp_allinfo->prev)
        tmp_allinfo = tmp_allinfo->prev;

    while(tmp_allinfo && tmp_allinfo->start != ptr)
        tmp_allinfo = tmp_allinfo->next;

    if(!tmp_allinfo)
        return NULL;

    newsize = LESSER(tmp_allinfo->size, size);

    memcpy(newptr, ptr, newsize);
    tmp_allinfo->free = 1;

    return newptr;
}
