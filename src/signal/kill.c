#include <signal.h>
#include <unistd.h>
#include <sys/syscall.h>

int kill(pid_t pid, int sig)
{
    return syscall(SYS_kill, pid, sig);
}
