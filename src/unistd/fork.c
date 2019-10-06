#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

pid_t __fork(void)
{
#if defined(SYS_fork)
    return __syscall(SYS_fork);
#else
    errno = ENOSYS;
    return -1;
#endif
}

weak_alias(__fork, fork);
