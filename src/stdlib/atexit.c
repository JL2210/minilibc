#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

void (*atexit_arr[ATEXIT_MAX])(void) = { NULL };
uint8_t atexit_ctr = 0;

int atexit(void (*func)(void))
{
	atexit_arr[atexit_ctr] = func;
	atexit_ctr++;
	return 0;
}
