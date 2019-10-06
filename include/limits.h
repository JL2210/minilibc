#ifndef _LIMITS_H
#define _LIMITS_H 1

#include <features.h>

#define ATEXIT_MAX 256
#define CHAR_BIT 8

#ifdef __GNUC__
# define UCHAR_MAX __UINT8_MAX__
# define SSIZE_MAX __INTPTR_MAX__
# define INT_MAX __INT_MAX__
# define INT_MIN __INT_MIN__
#else
# define UCHAR_MAX (~(unsigned char)0)
# define SSIZE_MAX (~(long)0)
# define INT_MAX ((~0)/2)
# define INT_MIN ((~0)/2+1)
#endif

#endif
