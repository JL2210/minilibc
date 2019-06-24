#include <unistd.h>
#include <sys/syscall.h>

int brk(void *ptr)
{
    if( (void *)syscall(SYS_brk, ptr) != ptr )
        return -1;
    else
        return 0;
}
