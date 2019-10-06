#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscall.h>

#include "libc-deps.h"

mode_t __umask(mode_t mode)
{
    return __syscall(SYS_umask, mode);
}

weak_alias(__umask, umask);
