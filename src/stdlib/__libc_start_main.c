#include <stdlib.h>
#include <stddef.h>

int __libc_start_main
(
int (*main)(int, char**, char**),
int argc,
char **argv
)
{
	int ret;

	__environ = argv + argc + 1;
	__auxv = *((Elf_auxv_t **)&__environ + 1);

	_init();
	ret = main(argc, argv, __environ);
	_fini();

	exit(ret);
}
