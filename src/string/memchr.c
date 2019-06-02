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

#include <string.h>

#define uc(x) ((unsigned char)(x))
#define ucp(x) ((unsigned char *)(x))

void *memchr(const void *ptr, int c, size_t len)
{
    size_t ctr;

    for( ctr = 0; ctr < len; ctr++ )
        if( ucp(ptr)[ctr] == uc(c) )
            return (void *)&ucp(ptr)[ctr];

    return NULL;
}
