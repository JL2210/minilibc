#include <unistd.h>
#include <sys/syscall.h>

int open(const char *path, int oflag, ...)
{
        return syscall(SYS_open, path, oflag);
}