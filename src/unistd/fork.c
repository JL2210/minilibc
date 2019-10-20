#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

pid_t __fork(void)
{
    return __syscall(SYS_fork);
}

weak_alias(__fork, fork);
