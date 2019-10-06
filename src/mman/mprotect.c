#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __mprotect(void *addr, size_t len, int prot)
{
    return __syscall(SYS_mprotect, addr, len, prot);
}

weak_alias(__mprotect, mprotect);
