#ifndef _SYS_CDEFS_H
#define _SYS_CDEFS_H 1

#include <features.h>

#if !(__GNUC__ <= 2 && __GNUC_MINOR__ <= 8)
# define __extension__
#endif

#if __GNUC__ < 2
# define __attribute__(x)
#endif

#if __STDC_VERSION__ >= 199901L || __cplusplus >= 201103L
# define __FUNCTION__ __func__
#else
# define __func__ __extension__ __FUNCTION__
#endif

#if __STDC_VERSION__ < 201112L || __cplusplus < 201103L
# define _Noreturn __attribute__((__noreturn__))
#elif __cplusplus >= 201103L
# define _Noreturn [[noreturn]]
#endif

#if !defined(__INTEL_COMPILER)
# define __pragma(x) _Pragma(#x)
#endif

#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#endif
