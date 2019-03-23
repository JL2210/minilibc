#ifndef _ALLOCA_H
#define _ALLOCA_H 1

#ifdef __GNUC__
# define alloca(x) __builtin_alloca(x)
#else
# define alloca(x) malloc(x)
#endif

#endif
