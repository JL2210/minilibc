#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H 1

#include <features.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef intptr_t ssize_t;
typedef ssize_t blkcnt_t;
typedef ssize_t time_t;
typedef ssize_t off_t;

#ifdef __cplusplus
}
#endif

#endif
