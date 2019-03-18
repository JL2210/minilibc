#ifndef _STDIO_H
#define _STDIO_H 1

#include <stddef.h>

#ifndef EOF
# define EOF -1
#endif

extern int puts(char *);
extern int printf(char *, ...);

#endif
