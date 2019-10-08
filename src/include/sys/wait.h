#ifndef SYS_WAIT_H
#define SYS_WAIT_H 1

#include "../../../include/sys/wait.h"

pid_t __wait3(int *, int, struct rusage *);
pid_t __wait4(pid_t, int *, int, struct rusage *);
pid_t __waitpid(pid_t, int *, int);

#endif
