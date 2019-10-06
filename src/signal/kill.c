#include <signal.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __kill(pid_t pid, int sig)
{
    return __syscall(SYS_kill, pid, sig);
}

weak_alias(__kill, kill);
