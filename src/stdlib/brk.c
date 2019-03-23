#include <unistd.h>

intptr_t brk(void *ptr)
{
	return syscall(SYS_brk, ptr);
}
