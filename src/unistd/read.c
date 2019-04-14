#include <stdio.h>
#include <unistd.h>

ssize_t read(int fd, const void *buf, size_t len)
{
    return (ssize_t)syscall(SYS_read, fd, buf, len);
}
