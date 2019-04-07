#ifndef _STDIO_H
#define _STDIO_H 1

#include <stddef.h>
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

#if 1
extern FILE stdin[];
extern FILE stdout[];
extern FILE stderr[];
#else
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
#endif

extern int puts(const char *);
extern int putchar(int);
extern int printf(const char *, ...);
extern int vprintf(const char *, va_list);
extern int vfprintf(FILE *, const char *, va_list);

#ifdef __cplusplus
}
#endif

#endif
