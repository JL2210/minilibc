#include <unistd.h>
#include <stddef.h>

void *sbrk(intptr_t inc)
{
	intptr_t curbrk = brk(NULL);

	if( curbrk < 0 ) return (void *)-1;

	brk((void *)(curbrk+inc));
	return (void *)curbrk;
}
