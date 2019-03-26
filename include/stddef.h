#ifndef _STDDEF_H
#define _STDDEF_H 1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
# ifndef __cplusplus
#  define NULL ((void *)0)
# else
#  define NULL 0
# endif
#endif

#ifdef __cplusplus
}
#endif

#endif
