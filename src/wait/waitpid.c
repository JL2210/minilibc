#include <sys/wait.h>
#include <stddef.h>

#include "libc-deps.h"

pid_t __waitpid(pid_t pid, int *wstatus, int options)
{
    return __wait4(pid, wstatus, options, NULL);
}

weak_alias(__waitpid, waitpid);
