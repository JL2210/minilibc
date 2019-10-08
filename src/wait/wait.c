#include <sys/wait.h>

#include "libc-deps.h"

pid_t __wait(int *wstatus)
{
    return __waitpid(-1, wstatus, 0);
}

weak_alias(__wait, wait);
