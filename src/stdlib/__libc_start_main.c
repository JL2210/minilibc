#include <stdlib.h>
#include <stddef.h>

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
	int ret;
	char *envp = NULL;

	(void)rtld_fini;
	(void)stack_end;
	if( (argc != 0) && (argv != NULL) )
		envp = *(argv + argc + 1);

	_init();
	ret = main(argc, argv, &envp);
	_fini();

	exit(ret);
}
