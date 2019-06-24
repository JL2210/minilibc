#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

time_t time(time_t *timeptr)
{
    return syscall(SYS_time, timeptr);
}
