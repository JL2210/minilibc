#ifndef _LIMITS_H
#define _LIMITS_H 1

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef UCHAR_MAX
# ifdef __UINT8_MAX__
#  define UCHAR_MAX __UINT8_MAX__
# else
#  define UCHAR_MAX ((unsigned char)-1)
# endif
#endif

#ifndef SSIZE_MAX
# ifdef __INTPTR_MAX__
#  define SSIZE_MAX __INTPTR_MAX__
# else
#  ifdef __SIZE_TYPE__
#   define SSIZE_MAX (((__SIZE_TYPE__)-1)/2)
#  else
#   define SSIZE_MAX (((unsigned long)-1)/2)
#  endif
# endif
#endif

#ifndef INT_MAX
# ifdef __INT_MAX__
#  define INT_MAX __INT_MAX__
# else
#  define INT_MAX (((unsigned)-1)/2)
# endif
#endif

#define ATEXIT_MAX 256
#define PATH_MAX 4096

#ifdef __cplusplus
}
#endif

#endif
