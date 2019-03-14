#include <stdlib.h>
#include <stdio.h>

int __libc_start_main
(
int (*main)(int, char**, char**),
int argc,
char **argv,
void (*_init)(void),
void (*_fini)(void),
void (*rtld_fini)(void),
void *stack_end
)
{

	char **envp = {NULL};
	if( (argc != 0) && (argv != NULL) )
		envp = argv + argc + 1;

	_init();
	exit(main(argc, argv, envp));

	return 0;
}
