#ifndef _FCNTL_H
#define _FCNTL_H 1

#include <features.h>

#define __need_off_t
#define __need_pid_t
#define __need_mode_t

#include <bits/alldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

#define O_RDONLY    0000000
#define O_WRONLY    0000001
#define O_RDWR      0000002
#define O_CREAT     0000100
#define O_EXCL      0000200
#define O_TRUNC     0001000
#define O_APPEND    0002000
#define O_LARGEFILE 0100000

extern int open(const char *, int, ...);

#ifdef __cplusplus
}
#endif

#endif
