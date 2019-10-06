#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __close(int fd)
{
#ifdef SYS_close
    return __syscall(SYS_close, fd);
#else
    errno = ENOSYS;
    return -1;
#endif
}

weak_alias(__close, close);
