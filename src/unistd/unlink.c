#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __unlink(const char *filename)
{
    return __unlinkat(AT_FDCWD, filename, 0);
}

weak_alias(__unlink, unlink);
