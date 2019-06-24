#ifndef _TIME_H
#define _TIME_H 1

#include <features.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct timespec
{
    time_t tv_sec;
    suseconds_t tv_nsec;
};

time_t time(time_t *);
int nanosleep(const struct timespec *, struct timespec *);

#ifdef __cplusplus
}
#endif

#endif
