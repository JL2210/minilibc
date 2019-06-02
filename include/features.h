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

#ifndef _FEATURES_H
#define _FEATURES_H 1

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__GNUC__) && !defined(__TINYC__)
# define __attribute__(x)
#endif

#if !defined(UINTPTR_MAX) && defined(__UINTPTR_MAX__)
# define UINTPTR_MAX __UINTPTR_MAX__
#endif

#if UINTPTR_MAX == 0xffffffffffffffffUL
# define __PTR64__
#elif UINTPTR_MAX == 0xffffffffUL
# define __PTR32__
#elif UINTPTR_MAX == 0xffffU
# define __PTR16__
#endif

#if defined(__STDC_VERSION__)
# if __STDC_VERSION__ < 201112L
#  define _Noreturn __attribute__((__noreturn__))
# endif
#else
# define _Noreturn __attribute__((__noreturn__))
#endif

#ifdef __cplusplus
}
#endif

#endif
