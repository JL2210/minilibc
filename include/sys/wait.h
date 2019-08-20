#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H 1

#include <features.h>

#define __need_pid_t
#define __need_rusage

#include <bits/alldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);

#ifdef __cplusplus
}
#endif

#endif
