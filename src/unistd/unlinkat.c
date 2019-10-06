#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __unlinkat(int dirfd, const char *filename, int flags)
{
    return __syscall(SYS_unlinkat, dirfd, filename, flags);
}

weak_alias(__unlinkat, unlinkat);
