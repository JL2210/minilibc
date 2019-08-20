#include <errno.h>

long __syscall(long syscall_num, long a, long b, long c, long d, long e, long f)
{
    (void)syscall_num;
    return -ENOSYS;
}
