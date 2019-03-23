#include <stdlib.h>
#include <unistd.h>

#if 1
extern void (*atexit_arr[])(void);
#else
extern void (**atexit_arr)(void);
#endif
extern uint8_t atexit_ctr;

_Noreturn void exit(int ret)
{
	int ctr = 0;

	for( ctr = 0; ctr < atexit_ctr; ctr++ )
		(atexit_arr[ctr])();
	_exit(ret);
}
