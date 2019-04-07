#include <unistd.h>
#include <stdnoreturn.h>

_Noreturn void _exit(int ret)
{
    (void)ret;
    while(1)
        syscall(SYS_exit, ret);
}
