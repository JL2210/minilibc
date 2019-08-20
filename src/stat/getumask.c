#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscall.h>

mode_t getumask(void)
{
    mode_t mask = umask(0);
    umask(mask);
    return mask;
}
