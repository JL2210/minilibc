#ifndef _STDNORETURN_H
#define _STDNORETURN_H 1

#include <features.h>

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L
# define _Noreturn
#endif

#define noreturn _Noreturn

#endif
