#include <sys/syscall.h>
#include <sys/types.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "libc-deps.h"

int __open(const char *pathname, int flags, ...)
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

    return __openat(AT_FDCWD, pathname, flags, mode);
}

weak_alias(__open, open);
