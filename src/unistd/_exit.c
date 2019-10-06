#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

_Noreturn void _exit(int ret)
{
    while(1)
    {
#ifdef SYS_exit_group
        __syscall(SYS_exit_group, ret);
#endif
#ifdef SYS_exit
        __syscall(SYS_exit, ret);
#endif
    }
}

weak_alias(_exit, _Exit);
