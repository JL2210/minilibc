#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/syscall.h>

int open(const char *pathname, int flags, ...)
{
    int ret;
    va_list ap;
    mode_t mode;

    va_start(ap, flags);
    mode = va_arg(ap, mode_t);
    ret = syscall(SYS_open, pathname, flags, mode);
    va_end(ap);

    return ret;
}
