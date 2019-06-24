#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/syscall.h>

pid_t wait3(int *status, int options, struct rusage *usage)
{
    return wait4(-1, status, options, usage);
}

