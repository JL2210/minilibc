#ifndef _VARARGS_H
#define _VARARGS_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* Not great, but it works... */
#warning <varargs.h> is deprecated. \
	 Revise your code to use <stdarg.h> instead.

#ifdef __i386__
# undef va_start
# undef va_alist
# undef va_list
# undef va_start
# undef va_end
# undef va_copy
# undef va_arg

# define va_alist __va_alist
# define va_dcl int __va_alist;
# define va_start(x) ((x) = (va_list)&__va_alist)
# define va_end(x) ((x) = (va_list)0)
# define va_copy(x,y) ((x) = (y))
# define va_arg(x,y) (*(*(y **)&x)++)
# ifdef __GNUC___
typedef __builtin_va_list va_list;
# else
typedef char *va_list;
# endif

#else
# error <varargs.h> has not been implemented for your platform yet.
#endif

#ifdef __cplusplus
}
#endif

#endif
