#include <elf.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdnoreturn.h>

extern void _init(void);
extern void _fini(void);
extern void fini_malloc(void);

#define AUX_NUM 38

_Noreturn int __libc_start_main
(
int (*main)(int, char**, char**, size_t*),
int argc,
char **argv
)
{
	int ret;
	Elf_auxv_t *auxv;

	__environ = argv + argc + 1;
	for( ret = 0; __environ[ret]; ret++ );
	auxv = (Elf_auxv_t *)__environ + ret + 1;
	size_t aux[AUX_CNT];
	for( ret = 0; ret < AUX_CNT; ret++ )
		aux[ret] = auxv[ret].a_un.a_value;

	_init();
	ret = main(argc, argv, __environ, aux);
	_fini();

	fini_malloc();

	exit(ret);
}
