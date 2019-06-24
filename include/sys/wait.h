#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H 1

#include <features.h>
#include <sys/types.h>
#include <sys/resource.h>

#ifdef __cplusplus
extern "C" {
#endif

pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);

#ifdef __cplusplus
}
#endif

#endif
