#include <unistd.h>
#include <stdint.h>
#include <sys/syscall.h>

#include "libc-deps.h"

off_t __lseek(int fd, off_t offset, int whence)
{
#ifdef SYS__llseek
    off_t result;
    return __syscall(SYS__llseek, fd, (uint32_t)(offset>>32),
                    (uint32_t)offset, &result, whence) ? -1 : result;
#else
    return __syscall(SYS_lseek, fd, offset, whence);
#endif
}

weak_alias(__lseek, lseek);
