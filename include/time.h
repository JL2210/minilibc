#ifndef _TIME_H
#define _TIME_H 1

#include <features.h>

#define __need_pid_t
#define __need_size_t
#define __need_time_t
#define __need_clock_t
#define __need_timer_t
#define __need_locale_t
#define __need_sigevent
#define __need_timespec
#define __need_clockid_t

#include <bits/alldefs.h>

__BEGIN_DECLS

time_t time(time_t *);
int nanosleep(const struct timespec *, struct timespec *);

__END_DECLS

#endif
