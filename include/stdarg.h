#ifndef _STDARG_H
#define _STDARG_H 1

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *va_list;
extern size_t *va_arg_c(va_list x, size_t y);
#define va_start(x, y)	x=&y+1
#define va_arg(x, y)	*(y*)va_arg_c(x, sizeof(y))
#define va_copy(x, y)	x=y;
#define va_end(x)	x=NULL;

#ifdef __cplusplus
}
#endif

#endif
