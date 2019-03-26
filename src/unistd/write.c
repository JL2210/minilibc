#include <stdio.h>
#include <unistd.h>

ssize_t write(int fd, const void *buf, int len)
{
	return (ssize_t)syscall(SYS_write, fd, buf, len);
}
