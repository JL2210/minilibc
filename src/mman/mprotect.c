#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>

int mprotect(void *addr, size_t len, int prot)
{
    return syscall(SYS_mprotect, addr, len, prot);
}
