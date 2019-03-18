#include <stdlib.h>

intptr_t syscall(intptr_t syscall_num, ...)
{
	(void)syscall_num;
	/* errno = ENOSYS; */
	return -1;
}
