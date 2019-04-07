#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H 1

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uintptr_t size_t;
typedef intptr_t ssize_t;
typedef ssize_t blkcnt_t;
typedef ssize_t time_t;
typedef ssize_t off_t;
typedef int ptrdiff_t;

#ifdef __cplusplus
}
#endif

#endif
