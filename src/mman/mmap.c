#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/syscall.h>

#include "libc-deps.h"

#ifdef SYS_mmap2
# undef SYS_mmap
# define SYS_mmap SYS_mmap2
# define poffset (unsigned long)(offset>>12)
#else
# define poffset offset
#endif

void *__mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    return (void *)__syscall(SYS_mmap, addr, length, prot,
                             flags, fd, poffset);
}

weak_alias(__mmap, mmap);
