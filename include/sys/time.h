#ifndef _SYS_TIME_H
#define _SYS_TIME_H 1

#include <features.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct timeval
{
    time_t tv_sec;
    suseconds_t tv_usec;
};

#ifdef __cplusplus
}
#endif

#endif
