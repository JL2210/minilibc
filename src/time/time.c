#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

time_t __time(time_t *timeptr)
{
    return __syscall(SYS_time, timeptr);
}

weak_alias(__time, time);
