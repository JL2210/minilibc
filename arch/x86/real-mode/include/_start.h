#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <newboot.h>

extern void _init(void);
extern void _fini(void);
extern int main(int argc, char **argv);

void _start(void)
{
	asm volatile (
		"\tmov %%cs, %%ax\n"
		"\tmov %%ax, %%ds\n"
		"\tmov %%ax, %%es\n"
		: : : "%ax"
	);
	void *ptr = NULL;
	char **argv, *args, *orig_args;
	char msg[] = "Enter argument list: ";
	unsigned int argc = 2, ret, ctr[2], len, offset[2];
	bios_clear();
	bios_setcursor(0);
	puts(msg);
	asm (
		"\tsub $0x0400, %%sp\n"
		"\tpush %%sp\n"
		"\tcall gets\n"
		"\tmov %%esp, %0\n"
		: "=r" (args)
		: : "cc"
		);
	orig_args = args;
	len = strlen(args);
	len++;
	for( ctr[0] = 0, ctr[1] = 1; ctr[0] < len; ctr[0]++ )
	{
		if( args[ctr[0]] == ' ' )
		{
			ctr[1]++;
			args[ctr[0]] = '\0';
		}
	}
	asm (
		"\tsub %1, %%esp\n"
		"\tmov %%esp, %0\n"
		: "=r" (argv)
		: "r" (ctr[1]*sizeof(char *))
		: "cc"
		);
	argv[0] = NULL;
	asm (
		"\tsub %1, %%esp\n"
		"\tmov %%esp, %0\n"
		: "=r" (ptr)
		: "r" (len)
		: "cc"
		);
	for( ctr[0] = 0; ctr[0] < 2; ctr[0]++ )
		offset[ctr[0]] = 0;
	for( ctr[0] = 1; ctr[0] < ctr[1] && args && offset[1] <= len; ctr[0]++, offset[0]++ )
	{
		argv[ctr[0]] = ptr;
		strcpy(argv[ctr[0]], args);
		offset[0] = (strchr(args, 0) - args) + 1;
		offset[1] = (offset[0] + args) - orig_args;
		args += offset[0];
		ptr += offset[0];
	}
	_init();
	ret = main(argc, argv);
	_fini();

	asm (
		"\tadd %0, %%esp\n"
		: : "r" (len+(ctr[1]*sizeof(char *))+0x0400)
		: "cc"
		);

	exit(ret);
}
