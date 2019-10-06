#include <unistd.h>
#include <sys/wait.h>
#include <sys/syscall.h>

#include "libc-deps.h"

pid_t __wait4(pid_t pid, int *status, int options, struct rusage *usage)
{
    return __syscall(SYS_wait4, pid, status, options, usage);
}

weak_alias(__wait4, wait4);
