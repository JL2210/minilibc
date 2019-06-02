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

#ifndef _STDINT_H
#define _STDINT_H 1

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef char int8_t;
typedef short int16_t;
#ifndef __PTR16__
typedef int int32_t;
#else
typedef long int32_t;
#endif
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
#ifndef __PTR16__
typedef unsigned int uint32_t;
#else
typedef unsigned long uint32_t;
#endif
#ifndef __PTR16__
typedef long long int64_t;
typedef unsigned long long uint64_t;
#endif
#if defined(__PTR64__)
typedef int64_t intptr_t;
typedef uint64_t uintptr_t;
#elif defined(__PTR32__)
typedef int32_t intptr_t;
typedef uint32_t uintptr_t;
#elif defined(__PTR16__)
typedef int16_t intptr_t;
typedef uint16_t uintptr_t;
#else
# error "Unknown data model."
#endif

#ifdef __cplusplus
}
#endif

#endif
