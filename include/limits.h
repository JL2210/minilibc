#ifndef _LIMITS_H
#define _LIMITS_H 1

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__UINT8_MAX__) && !defined(UCHAR_MAX)
# define UCHAR_MAX __UINT8_MAX__
#endif
#if defined(__INTPTR_MAX__) && !defined(SSIZE_MAX)
# define SSIZE_MAX __INTPTR_MAX__
#endif
#if defined(__INT_MAX__) && !defined(INT_MAX)
# define INT_MAX __INT_MAX__
#endif

#define ATEXIT_MAX 128
#define PATH_MAX 4096

#ifdef __cplusplus
}
#endif

#endif
