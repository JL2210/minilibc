#ifndef _STDIO_H
#define _STDIO_H 1

#include <stddef.h>
#include <stdarg.h>

struct
{
	int fd;
	void *ptr;
} FILE;

#ifndef EOF
# define EOF -1
#endif

extern int puts(char *);
extern int putchar(int);
extern int printf(char *, ...);
extern ssize_t write(int, char *, int);

#endif
