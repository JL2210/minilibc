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

#define GREATER(x,y) ((x) > (y) ? (x) : (y))

int strcmp(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1),
           len2 = strlen(str2);
    return strncmp(str1, str2, GREATER(len1, len2));
}
