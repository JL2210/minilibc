#ifndef _FEATURES_H
#define _FEATURES_H 1

#include <sys/cdefs.h>

#ifndef __STRICT_ANSI__
# define _DEFAULT_SOURCE 1
#endif

#if !defined(__GNUC__) && !defined(__TINYC__)
# define __attribute__(x)
# define __extension__
#endif

#if !defined(_MSC_VER) && !defined(__INTEL_COMPILER)
# define __pragma(x) _Pragma(#x)
#endif

#if __STDC_VERSION__ < 201112L
# define _Noreturn __attribute__((__noreturn__))
#endif

#endif
