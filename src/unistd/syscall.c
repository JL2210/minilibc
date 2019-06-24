#include <errno.h>

#ifdef __cplusplus
# define C_LINKAGE extern "C"
#else
# define C_LINKAGE
#endif

C_LINKAGE
long __syscall(long, long, long, long, long, long, long);

C_LINKAGE
long syscall(long a, long b, long c, long d, long e, long f, long g)
{
        long ret;

        ret = __syscall(a, b, c, d, e, f, g);

        if((unsigned long)ret > (unsigned long)-4096)
        {
                errno = -ret;
                ret = -1;
        }

        return ret;
}
