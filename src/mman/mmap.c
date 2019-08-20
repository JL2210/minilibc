#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>

#ifdef SYS_mmap2
# undef SYS_mmap
# define SYS_mmap SYS_mmap2
# define poffset offset/4096ULL
#else
# define poffset offset
#endif

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    return (void *)syscall(SYS_mmap, addr, length, prot, flags, fd, poffset);
}
