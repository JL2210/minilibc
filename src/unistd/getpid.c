#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

pid_t __getpid(void)
{
    return __syscall(SYS_getpid);
}

weak_alias(__getpid, getpid);
