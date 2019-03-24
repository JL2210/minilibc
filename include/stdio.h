#ifndef _STDIO_H
#define _STDIO_H 1

#include <stddef.h>
#include <stdarg.h>

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

extern int puts(char *);
extern int putchar(int);
extern int printf(char *, ...);
extern int vprintf(char *str, va_list ap);
extern int vfprintf(FILE *fp, char *fmt, va_list ap);

#endif
