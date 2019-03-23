#include <elf.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

extern void _init(void);
extern void _fini(void);

int __libc_start_main
(
int (*main)(int, char**, char**, Elf_auxv_t*),
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

	_init();
	ret = main(argc, argv, __environ, auxv);
	_fini();

	exit(ret);
}
