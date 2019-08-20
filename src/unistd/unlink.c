#include <unistd.h>
#include <sys/syscall.h>

int unlink(const char *filename)
{
    return syscall(SYS_unlink, filename);
}
