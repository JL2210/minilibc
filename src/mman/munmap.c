#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>

#include "libc-deps.h"

int __munmap(void *addr, size_t length)
{
    return __syscall(SYS_munmap, addr, length);
}

weak_alias(__munmap, munmap);
