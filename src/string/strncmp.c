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

#define ucp(x) ((unsigned char *)(x))

int strncmp(const char *ptr1, const char *ptr2, size_t n)
{
    size_t ctr;

    for( ctr = 0; ctr < n && ucp(ptr1)[ctr-1] && ucp(ptr2)[ctr-1]; ctr++ )
    {
        if(ucp(ptr1)[ctr] > ucp(ptr2)[ctr]) goto not_equal;
        else if(ucp(ptr2)[ctr] > ucp(ptr1)[ctr]) goto not_equal;
    }
    return 0;
not_equal:
    return ucp(ptr1)[ctr] - ucp(ptr2)[ctr];
}
