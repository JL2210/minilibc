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

#ifndef _STDIO_H
#define _STDIO_H 1

#include <features.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

struct _FILE
{
    int fd;
};

typedef struct _FILE FILE;

#ifndef EOF
# define EOF -1
#endif

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

extern int puts(const char *);
extern int fputs(const char *, FILE *);
extern int printf(const char *, ...);
extern int vprintf(const char *, va_list);
extern int vfprintf(FILE *, const char *, va_list);
extern char *fgets(char *, int, FILE *);
#if __STDC_VERSION__ < 201112L
extern char *gets(char *);
#endif
extern int fgetc(FILE *);
extern int getchar(void);
#define getc fgetc
extern int fputc(int, FILE *);
extern int putchar(int);
extern int fileno(FILE *);

#ifdef __cplusplus
}
#endif

#endif
