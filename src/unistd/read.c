#include <unistd.h>
#include <sys/syscall.h>

ssize_t read(int fd, void *buf, size_t len)
{
    return (ssize_t)syscall(SYS_read, fd, buf, len);
}
