#ifndef _STDINT_H
#define _STDINT_H 1

#if defined(__GNUC__)
# define UINTPTR_MAX __UINTPTR_MAX__
# define INTPTR_MAX __INTPTR_MAX__
#endif

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;
#if UINTPTR_MAX == 0xffffffffffffffffUL
typedef int64_t intptr_t;
typedef uint64_t uintptr_t;
#elif UINTPTR_MAX == 0xffffffffUL
typedef int32_t intptr_t;
typedef uint32_t uintptr_t;
#elif UINTPTR_MAX == 0xffffUL
typedef int16_t intptr_t;
typedef uint16_t uintptr_t;
#else
# error "Unknown data model."
#endif
typedef uintptr_t size_t;

#endif
