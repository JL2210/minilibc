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

#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H 1

#include <features.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PROT_NONE      (0x0)
#define PROT_READ      (0x1)
#define PROT_WRITE     (1<<1)
#define PROT_EXEC      (1<<2)

#ifdef __cplusplus
# define MAP_FAILED    (-1)
#else
# define MAP_FAILED    ((void *)-1)
#endif

#define MAP_FILE       (0x0)
#define MAP_SHARED     (0x1)
#define MAP_PRIVATE    (0x2)
#define MAP_FIXED      (0x10)
#define MAP_ANONYMOUS  (0x20)
#define MAP_ANON       MAP_ANONYMOUS

extern void *mmap(void *, size_t, int, int, int, off_t);
extern int munmap(void *, size_t);

#ifdef __cplusplus
}
#endif

#endif
