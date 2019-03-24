#ifndef _FEATURES_H
#define _FEATURES_H 1

#if defined(__GNUC__)
# define UINT8_MAX __UINT8_MAX__
# define UCHAR_MAX UINT8_MAX
# define UINTPTR_MAX __UINTPTR_MAX__
# define INTPTR_MAX __INTPTR_MAX__
# define SSIZE_MAX INTPTR_MAX
# if defined(__STDC_VERSION__) && __STDC_VERSION__ < 201112L
#  define _Noreturn __attribute__((__noreturn__))
# endif
#endif

#endif
