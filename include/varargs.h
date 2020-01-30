#ifndef _VARARGS_H
#define _VARARGS_H 1

#include <features.h>

#define __need___va_list

#include <bits/defs.h>

#ifdef __GNUC__
# warning <varargs.h> is deprecated. \
      Revise your code to use <stdarg.h> instead.
#endif

typedef __va_list va_list;

#ifdef __i386__
# define va_alist __va_alist
# define va_dcl int __va_alist;
# define va_start(x) ((x) = (va_list)&__va_alist)
# define va_end(x) ((x) = (va_list)0)
# define va_copy(x,y) ((x) = (y))
# define va_arg(x,y) (*(*(y **)&(x))++)
#else
# error <varargs.h> has not been implemented for your platform yet.
#endif

#endif
