#include <unistd.h>
#include <stdarg.h>
#include <sys/syscall.h>

#ifdef __cplusplus
extern "C"
#endif
int open(const char *pathname, int flags, mode_t mode)
{
    return syscall(SYS_open, pathname, flags, mode);
}
