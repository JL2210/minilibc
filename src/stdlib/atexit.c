#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

#if 1
void (*atexit_arr[ATEXIT_MAX])(void) = { NULL };
#else
void (**atexit_arr)(void) = { NULL };
#endif
uint8_t atexit_ctr = 0;

int atexit(void (*func)(void))
{
#if 0
	atexit_arr = (void **)realloc(atexit_arr, (atexit_ctr+1)*sizeof(void **));
#endif
	atexit_arr[atexit_ctr] = func;
	atexit_ctr++;
	return 0;
}
