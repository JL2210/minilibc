#include <errno.h>

long __syscall(long syscall_num, ...)
{
    (void)syscall_num;
    return -ENOSYS;
}
