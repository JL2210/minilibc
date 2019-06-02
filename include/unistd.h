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

#ifndef _UNISTD_H
#define _UNISTD_H 1

#include <features.h>
#include <stdint.h>
#include <sys/types.h>
#include <bits/unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _POSIX_VERSION 200809L
#define _POSIX2_VERSION 200809L
#define _XOPEN_VERSION 700

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define __environ environ
#define _environ environ
extern char **environ;

extern _Noreturn void _exit(int);

extern intptr_t syscall(intptr_t, ...);

extern void *sbrk(intptr_t);
extern int brk(void *);
extern ssize_t write(int, const void *, size_t);
extern ssize_t read(int, void *, size_t);

#ifdef __cplusplus
}
#endif

#endif
