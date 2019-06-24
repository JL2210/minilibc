#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H 1

#include <features.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long useconds_t;
typedef long suseconds_t;
typedef unsigned mode_t;
typedef long blkcnt_t;
typedef int blksize_t;
typedef long ssize_t;
typedef long time_t;
typedef long off_t;
typedef int dev_t;
typedef int pid_t;

#ifdef __cplusplus
}
#endif

#endif
