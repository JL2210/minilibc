#ifndef _STDARG_H
#define _STDARG_H 1

#include <stddef.h>
#include <stdint.h>

typedef void *va_list;
extern size_t *va_arg_c(va_list x, size_t y);
#define va_start(x, y)	x=(void *)&y+1
#define va_arg(x, y)	*(y*)va_arg_c(x, sizeof(y))
#define va_copy(x, y)	x=y;
#define va_end(x)	x=NULL;

#endif
