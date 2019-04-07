#ifndef _VARARGS_H
#define _VARARGS_H 1

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Not great, but it works... */
#define va_alist int _va_alist, ...
#define va_dcl
#define va_start(p) va_start(p, _va_alist)
#error <varargs.h> is deprecated. Use <stdarg.h> instead.

#ifdef __cplusplus
}
#endif

#endif
