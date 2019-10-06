#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __nanosleep(const struct timespec *req, struct timespec *rem)
{
    return __syscall(SYS_nanosleep, req, rem);
}

weak_alias(__nanosleep, nanosleep);
