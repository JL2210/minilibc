#include <stdlib.h>

intptr_t syscall(long syscall_num, ...)
{
	(void)syscall_num;
	/* errno = ENOSYS; */
	return -1;
}
