#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>

mode_t umask(mode_t mode)
{
    return syscall(SYS_umask, mode);
}
