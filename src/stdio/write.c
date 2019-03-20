#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t write(int fd, char *str, int len)
{
	return (ssize_t)syscall(SYS_write, fd, str, len);
}
