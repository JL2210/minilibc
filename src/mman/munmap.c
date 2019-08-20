#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>

int munmap(void *addr, size_t length)
{
    return syscall(SYS_munmap, addr, length);
}
