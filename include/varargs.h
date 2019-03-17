#ifndef _VARARGS_H
#define _VARARGS_H 1

#include <stdarg.h>
/* Not great, but it works... */
#define va_alist int _va_alist, ...
#define va_dcl
#define va_start(p) va_start(p, _va_alist)
#warning <varargs.h> is deprecated. Use <stdarg.h> instead.

#endif
