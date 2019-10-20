#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

void *__sbrk(intptr_t inc)
{
#if defined(SYS_brk)
    char *curbrk = (char *)__syscall(SYS_brk, NULL);

    if(inc)
        if((char *)__syscall(SYS_brk, curbrk+inc) != curbrk+inc)
            curbrk = (char *)-1;

    return curbrk;
#elif defined(SYS_sbrk)
    return __syscall(SYS_sbrk, inc);
#endif
}

weak_alias(__sbrk, sbrk);
