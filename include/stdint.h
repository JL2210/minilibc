#ifndef _STDINT_H
#define _STDINT_H 1

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long intptr_t;
__extension__ typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uintptr_t;
__extension__ typedef unsigned long long uint64_t;

#if defined(__UINT8_MAX__) && !defined(UINT8_MAX)
# define UINT8_MAX __UINT8_MAX__
#endif

#if defined(__INTPTR_MAX__) && !defined(INTPTR_MAX)
# define INTPTR_MAX __INTPTR_MAX__
#endif

#if defined(__UINTPTR_MAX__) && !defined(UINTPTR_MAX)
# define UINTPTR_MAX __UINTPTR_MAX__
#endif

#if defined(__SIZE_MAX__) && !defined(SIZE_MAX)
# define SIZE_MAX __SIZE_MAX__
#endif

#ifdef __cplusplus
}
#endif

#endif
