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

#ifndef _STRING_H
#define _STRING_H 1

#include <features.h>
#include <stddef.h>
#include <locale.h>

#ifdef __cplusplus
extern "C" {
#endif

#define strupr __strupr
#define strlwr __strlwr

extern size_t strlen(const char *);
extern size_t strnlen(const char *, size_t);

extern char *strdup(const char *);
extern char *strndup(const char *, size_t);

extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);
extern void *memcpy(void *, const void *, size_t);

extern int strcmp(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern int memcmp(const void *, const void *, size_t);

extern char *strchr(const char *, int);
extern void *memchr(const void *, int, size_t);

extern long long strtoll(const char *, char **, int);
extern unsigned long long strtoull(const char *, char **, int);
extern long strtol(const char *, char **, int);
extern unsigned long strtoul(const char *, char **, int);

extern void *memset(void *, int, size_t);

extern char *strupr(char *);
extern char *strlwr(char *);

#ifdef __cplusplus
}
#endif

#endif
