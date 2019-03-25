#ifndef _FEATURES_H
#define _FEATURES_H 1

#if !defined(__GNUC__) && !defined(__TINYC__)
# define __attribute__(x)
#endif

#ifdef __UINT8_MAX__
# define UINT8_MAX __UINT8_MAX__
# define UCHAR_MAX UINT8_MAX
#endif
#ifdef __UINTPTR_MAX__
# define UINTPTR_MAX __UINTPTR_MAX__
#endif
#ifdef __INTPTR_MAX__
# define INTPTR_MAX __INTPTR_MAX__
# define SSIZE_MAX INTPTR_MAX
#endif
#ifdef __SIZE_TYPE__
# define SIZE_TYPE __SIZE_TYPE__
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ < 201112L
# define _Noreturn __attribute__((__noreturn__))
#endif

#endif
