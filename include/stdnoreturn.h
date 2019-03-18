#ifndef _STDNORETURN_H
#define _STDNORETURN_H 1

#if defined(__GNUC__) && defined(__STDC_VERSION__) && __STDC_VERSION__ < 201112L
# define _Noreturn __attribute__((__noreturn__))
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
/* Do nothing. */
#else
# define _Noreturn
#endif

#define noreturn _Noreturn

#endif
