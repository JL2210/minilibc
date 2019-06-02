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

#ifndef _LIMITS_H
#define _LIMITS_H 1

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__UINT8_MAX__) && !defined(UINT8_MAX) && !defined(UCHAR_MAX)
# define UINT8_MAX __UINT8_MAX__
# define UCHAR_MAX UINT8_MAX
#endif
#if defined(__UINTPTR_MAX__) && !defined(UINTPTR_MAX)
# define UINTPTR_MAX __UINTPTR_MAX__
#endif
#if defined(__SIZE_MAX__) && !defined(SIZE_MAX)
# define SIZE_MAX __SIZE_MAX__
#endif
#if defined(__INTPTR_MAX__) && !defined(INTPTR_MAX) && !defined(SSIZE_MAX)
# define INTPTR_MAX __INTPTR_MAX__
# define SSIZE_MAX INTPTR_MAX
#endif

#define ATEXIT_MAX 128

#ifdef __cplusplus
}
#endif

#endif
