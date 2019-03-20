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
	Elf_auxv_t *auxv;

	__environ = argv + argc + 1;
	for( ret = 0; __environ[ret]; ret++ );
	auxv = (Elf_auxv_t *)__environ + ret + 1;
	ret = 0;
	__hwcap = auxv[AT_HWCAP].a_un.a_val;
	__sysinfo = auxv[AT_SYSINFO].a_un.a_val;

	_init();
	ret = main(argc, argv, __environ);
	_fini();

	exit(ret);
}
