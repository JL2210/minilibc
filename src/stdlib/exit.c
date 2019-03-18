#include <stdlib.h>

_Noreturn void exit(int ret)
{
	int ctr = 0;

	for( ctr = 0; ctr < atexit_ctr; ctr++ )
		(atexit_arr[ctr])();
	_exit(ret);
}
