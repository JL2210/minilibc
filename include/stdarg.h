#ifndef _STDARG_H
#define _STDARG_H 1

#include <features.h>

#define __need_va_list

#include <bits/alldefs.h>

#if defined(__GNUC__)
# define __va_copy(x, y) __builtin_va_copy(x, y)
# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#  define va_copy(x, y) __va_copy(x, y)
# endif
# define va_start(x, y) __builtin_va_start(x, y)
# define va_arg(x, y) __builtin_va_arg(x, y)
# define va_end(x) __builtin_va_end(x)
#else
# if defined(__i386__) || defined(__i386)
#  define __va_copy(x,y) ((x) = (y))
#  if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#   define va_copy(x,y) __va_copy(x, y)
#  endif
#  define va_start(x, y) ((x) = (va_list)(&(y)+1))
#  define va_end(x) ((x) = (va_list)0)
#  define va_arg(x,y) (*(*(y **)&(x))++)
# else
#  error "<stdarg.h> has not been implemented for your platform."
# endif
#endif

#endif
