#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscall.h>

mode_t umask(mode_t mode)
{
    return syscall(SYS_umask, mode);
}
