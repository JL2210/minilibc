#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H 1

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef char int8_t;
typedef short int16_t;
#ifndef __PTR16__
typedef int int32_t;
#else
typedef long int32_t;
#endif
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
#ifndef __PTR16__
typedef unsigned int uint32_t;
#else
typedef unsigned long uint32_t;
#endif
#ifndef __PTR16__
typedef long long int64_t;
typedef unsigned long long uint64_t;
#endif
#if defined(__PTR64__)
typedef int64_t intptr_t;
typedef uint64_t uintptr_t;
#elif defined(__PTR32__)
typedef int32_t intptr_t;
typedef uint32_t uintptr_t;
#elif defined(__PTR16__)
typedef int16_t intptr_t;
typedef uint16_t uintptr_t;
#else
# error "Unknown data model."
#endif

typedef uintptr_t size_t;
typedef intptr_t ssize_t;
typedef ssize_t blkcnt_t;
typedef ssize_t off_t;
typedef int ptrdiff_t;

#ifdef __cplusplus
}
#endif

#endif
