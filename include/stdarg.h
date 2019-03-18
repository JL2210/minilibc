#ifndef _STDARG_H
#define _STDARG_H 1

#include <stddef.h>
#include <stdint.h>

typedef void *va_list;
#define va_start(x, y)	x=(void *)&y+1
#define va_arg(x, y)	*(intptr_t *)&x+=sizeof(y)
#define va_end(x)	x=NULL;

#endif
