#include <time.h>
#include <unistd.h>

#include "libc-deps.h"

int __usleep(useconds_t us)
{
    struct timespec tv;

    tv.tv_sec = us / 1000000;
    tv.tv_nsec = (us % 1000000) * 1000;

    return __nanosleep(&tv, &tv);
}

weak_alias(__usleep, usleep);
