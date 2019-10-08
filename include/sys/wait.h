#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H 1

#include <features.h>

#define __need_pid_t
#define __need_time_t
#define __need_rusage
#define __need_timeval
#define __need_suseconds_t

#include <bits/alldefs.h>

__BEGIN_DECLS

pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);
pid_t waitpid(pid_t, int *, int);
pid_t wait(int *);

__END_DECLS

#endif
