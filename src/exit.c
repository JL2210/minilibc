#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

void __attribute__((__visibility__("hidden"))) (*atexit_arr[ATEXIT_MAX])(void) = { NULL };
uint8_t __attribute__((__visibility__("hidden"))) atexit_ctr = 0;

int atexit(void (*func)(void))
{
	atexit_arr[atexit_ctr] = func;
	atexit_ctr++;
	return 0;
}

_Noreturn void exit(int ret)
{
	int ctr = 0;

	for( ctr = 0; ctr < atexit_ctr; ctr++ )
		(atexit_arr[ctr])();
	_exit(ret);
	while(1);
}

_Noreturn void _exit(int ret)
{
	_fini();
	while(1);
}
