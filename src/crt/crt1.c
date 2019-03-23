#include <stdlib.h>
#include <elf.h>

#include "_start.h"

extern int __libc_start_main
(
int (*)(int, char**, char**, Elf_auxv_t*),
int,
char **
);
extern int main(int, char**, char**, Elf_auxv_t*);

void _c_start(intptr_t *ptr)
{
	int argc = *ptr;
	char **argv = (char **)ptr+1;

	__libc_start_main(main, argc, argv);
}
