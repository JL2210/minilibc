#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H 1

#include <features.h>

#if UINTPTR_MAX == 0xffffffffffffffffUL
# define PTR64
#elif UINTPTR_MAX == 0xffffffffUL
# define PTR32
#elif UINTPTR_MAX == 0xffffUL
# define PTR16
#endif

typedef char int8_t;
typedef short int16_t;
#ifndef PTR16
typedef int int32_t;
#else
typedef long int32_t;
#endif
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
#ifndef PTR16
typedef unsigned int uint32_t;
#else
typedef unsigned long uint32_t;
#endif
#ifndef PTR16
typedef long long int64_t;
typedef unsigned long long uint64_t;
#endif
#if defined(PTR64)
typedef int64_t intptr_t;
typedef uint64_t uintptr_t;
#elif defined(PTR32)
typedef int32_t intptr_t;
typedef uint32_t uintptr_t;
#elif defined(PTR16)
typedef int16_t intptr_t;
typedef uint16_t uintptr_t;
#else
# error "Unknown data model."
#endif

typedef uintptr_t size_t;
typedef intptr_t ssize_t;
typedef int ptrdiff_t;

#undef PTR64
#undef PTR32
#undef PTR16

#endif
