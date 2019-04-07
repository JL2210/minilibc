#ifndef _STDARG_H
#define _STDARG_H 1

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *va_list;
#define va_arg(x, y)
#define va_start(x, y)
#define va_end(x)

#ifdef __cplusplus
}
#endif

#endif
