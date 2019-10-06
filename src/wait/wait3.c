#include <sys/wait.h>

#include "libc-deps.h"

pid_t __wait3(int *status, int options, struct rusage *usage)
{
    return __wait4(-1, status, options, usage);
}

weak_alias(__wait3, wait3);
