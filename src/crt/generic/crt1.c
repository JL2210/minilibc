/* Generic _start function */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern int main(int argc, char **argv, char **envp);

#warning \
	The C version of _start cannot determine\
	the name of a program, its arguments, or\
	environment variables.

void _start(void)
{
	char argv[1];
	argv[1] = '\0';

	__libc_start_main(main, 0, &argv, _init, _fini, NULL, NULL);
}
