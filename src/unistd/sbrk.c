#include <unistd.h>
#include <stddef.h>

extern int8_t brk_lock;

void *sbrk(intptr_t inc)
{
	while(brk_lock);
	brk_lock = 1;
	intptr_t curbrk = syscall(SYS_brk, NULL);
	brk_lock = 0;

	if( inc == 0 )
		goto ret;

	if( (curbrk < 0) || (brk((void *)(curbrk+inc)) == -1) )
		return (void *)-1;
ret:
	return (void *)curbrk;
}
