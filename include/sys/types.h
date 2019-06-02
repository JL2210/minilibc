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

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H 1

#include <features.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef __INTPTR_TYPE__ ssize_t;
typedef ssize_t blkcnt_t;
typedef ssize_t time_t;
typedef ssize_t off_t;

#ifdef __cplusplus
}
#endif

#endif
