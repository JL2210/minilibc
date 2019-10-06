#ifndef TIME_H
#define TIME_H 1

#include_next <time.h>

int __nanosleep(const struct timespec *, struct timespec *);

#endif
