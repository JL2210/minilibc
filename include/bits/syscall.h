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

#ifndef _BITS_SYSCALL_H
#define _BITS_SYSCALL_H 1

#ifndef _SYS_SYSCALL_H
# error Do not include <bits/syscall.h> directly; use <sys/syscall.h> instead.
#endif

#if defined(__LP64__)
# include <bits/syscall_64.h>
#elif defined(__ILP32__)
# include <bits/syscall_x32.h>
#else
# include <bits/syscall_32.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

#endif
