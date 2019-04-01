#include <unistd.h>
#include <stddef.h>

void *sbrk(intptr_t inc)
{
	intptr_t curbrk = syscall(SYS_brk, NULL);

	if( inc == 0 )
		goto ret;

	if( (curbrk < 0) || (brk((void *)(curbrk+inc)) == -1) )
		return (void *)-1;
ret:
	return (void *)curbrk;
}
