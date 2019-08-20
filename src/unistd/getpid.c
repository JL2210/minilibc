#include <unistd.h>
#include <sys/syscall.h>

pid_t getpid(void)
{
    return syscall(SYS_getpid);
}
