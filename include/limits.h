#ifndef _LIMITS_H
#define _LIMITS_H 1

#include <features.h>

#define ATEXIT_MAX 32

#ifdef __CHAR_BIT__
# define CHAR_BIT __CHAR_BIT__
#else
# define CHAR_BIT 8
#endif

#ifdef __UINT8_MAX__
# define UCHAR_MAX __UINT8_MAX__
#else
# define UCHAR_MAX 255 /* (~(unsigned char)0) */
#endif

#ifdef __LONG_MAX__
# define SSIZE_MAX __LONG_MAX__
#else
# define SSIZE_MAX LONG_MAX
#endif

#ifdef __INT_MAX__
# define INT_MAX __INT_MAX__
#else
# define INT_MAX 2147483647 /* ((~0)/2) */
#endif

#ifdef __INT_MIN__
# define INT_MIN __INT_MIN__
#else
# define INT_MIN (-INT_MAX-1)
#endif

#ifdef __LONG_MAX__
# define LONG_MAX __LONG_MAX__
#else
# define LONG_MAX ((~0L)/2)
#endif

#ifdef __LONG_MIN__
# define LONG_MIN __LONG_MIN__
#else
# define LONG_MIN (-LONG_MAX-1)
#endif

#ifdef __LLONG_MAX__
# define LLONG_MAX __LLONG_MAX__
#else
# define LLONG_MAX 9223372036854775807LL
#endif

#ifdef __LLONG_MIN__
# define LLONG_MIN __LLONG_MIN__
#else
# define LLONG_MIN (-LLONG_MAX-1)
#endif

#endif
