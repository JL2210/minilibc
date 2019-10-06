#include <sys/syscall.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <errno.h>

#include "libc-deps.h"

int __openat(int dirfd, const char *pathname, int flags, ...)
{
    mode_t mode = 0;

    flags |= O_LARGEFILE;

    if(flags & O_CREAT)
    {
        va_list ap;
        va_start(ap, flags);
        mode = va_arg(ap, mode_t);
        va_end(ap);
    }

#if defined(SYS_openat)
    return __syscall(SYS_openat, dirfd, pathname, flags, mode);
#else
# if defined(SYS_open)
    if(dirfd == AT_FDCWD)
        return __syscall(SYS_open, pathname, flags, mode);
# endif
    errno = ENOSYS;
    return -1;
#endif
}

weak_alias(__openat, openat);
