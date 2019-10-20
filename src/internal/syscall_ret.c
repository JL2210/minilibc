#include <errno.h>

long __syscall_ret(unsigned long ret)
{
    if(ret > -4096UL)
    {
        errno = -ret;
        return -1;
    }
    return (long)ret;
}
