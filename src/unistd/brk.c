#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __brk(void *ptr)
{
#if defined(SYS_brk)
    if((void *)__syscall(SYS_brk, ptr) != ptr)
        return -1;
    else
        return 0;
#elif defined(SYS_sbrk)
    void *br = (void *)__syscall(SYS_sbrk, 0);
    if((void *)__syscall(SYS_sbrk, br - ptr) != ptr)
        return -1;
    else
        return 0;
#else
    errno = ENOSYS;
    return -1;
#endif
}

weak_alias(__brk, brk);
