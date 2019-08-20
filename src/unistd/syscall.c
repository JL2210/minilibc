#include <errno.h>
#include <unistd.h>

long __syscall(long, long, long, long, long, long, long);

static long ex_syscall(long sys, long a, long b, long c, long d, long e, long f)
{
        long ret;

        ret = __syscall(sys, a, b, c, d, e, f);

        if((unsigned long)ret > (unsigned long)-4096)
        {
                errno = -ret;
                ret = -1;
        }

        return ret;
}

long (*syscall)(long sys, ...) = (long (*)(long, ...))((void *)ex_syscall);
