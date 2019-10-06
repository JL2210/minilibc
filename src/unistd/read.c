#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

ssize_t __read(int fd, void *buf, size_t len)
{
    return __syscall(SYS_read, fd, buf, len);
}

weak_alias(__read, read);
