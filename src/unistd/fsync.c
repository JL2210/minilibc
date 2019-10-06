#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __fsync(int fd)
{
    return __syscall(SYS_fsync, fd);
}

weak_alias(__fsync, fsync);
