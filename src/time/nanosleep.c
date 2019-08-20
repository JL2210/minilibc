#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    return syscall(SYS_nanosleep, req, rem);
}
