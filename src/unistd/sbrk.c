#include <unistd.h>
#include <sys/syscall.h>

void *sbrk(intptr_t inc)
{
    long curbrk = syscall(SYS_brk, NULL);

    if( inc == 0 )
        goto ret;

    if(syscall(SYS_brk, curbrk+inc) != curbrk+inc)
        curbrk = -1;
ret:
    return (void *)curbrk;
}
