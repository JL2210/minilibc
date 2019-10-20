#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __close(int fd)
{
    return __syscall(SYS_close, fd);
}

weak_alias(__close, close);
