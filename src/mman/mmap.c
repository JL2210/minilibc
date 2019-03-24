#include <sys/mman.h>
#include <unistd.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	return (void *)syscall(SYS_mmap, addr, length, prot, flags, fd, offset);
}