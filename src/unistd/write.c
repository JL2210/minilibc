#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

ssize_t __write(int fd, const void *buf, size_t len)
{
    return (ssize_t)__syscall(SYS_write, fd, buf, len);
}

weak_alias(__write, write);
