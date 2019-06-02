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

#ifndef _ASSERT_H
#define _ASSERT_H 1

#include <features.h>

#ifdef NDEBUG
#define assert(ignore)((void) 0)
#else
# define assert(x) (!(x) ? __assert_c(#x, __FILE__, __LINE__, __func__) : (void)0)
#endif

extern _Noreturn void __assert_c(char *assertion, char *file, int line, char *func);

#endif
