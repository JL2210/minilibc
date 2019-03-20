#include <stdlib.h>

#include "_start.h"

extern int main(int, char**, char**);

void _c_start(intptr_t *ptr)
{
	int argc = *ptr;
	char **argv = (char **)ptr+1;

	__libc_start_main(main, argc, argv);
}
