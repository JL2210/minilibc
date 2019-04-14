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
		"\tmov $0x07e0, %ax\n"
		"\tmov %ax, %ss\n"
		"\tmov $-1, %sp\n"
		"\tpush %cs\n"
		"\tpop %ds\n"
	);
	char *ss = (void *)0x7e00, *new_ss, **argv;
	char msg[] = "Enter argument list: ";
	unsigned int argc = 2, ret, ctr[2], len;
	bios_clear();
	bios_setcursor(0);
	bios_write((int16_t)(int32_t)msg, sizeof(msg));
	gets(ss);
	len = strlen(ss);
	len++;
	new_ss = ss + len;
	argv = (void *)new_ss;
	for( ctr[0] = 0; ctr[0] < len; ctr[0]++ )
		if( ss[ctr[0]] == ' ' ) argc++;
	new_ss += sizeof(argv) * argc;
	for( ctr[0] = 0; ctr[0] < argc; ctr[0]++ )
	{
		argv[ctr[0]] = new_ss;
		for( ctr[1] = 0; (ss[ctr[1]] != ' ') && (ss[ctr[1]] != '\0'); ctr[1]++ )
			argv[ctr[0]][ctr[1]] = ss[ctr[1]];
		argv[ctr[0]][ctr[1]] = '\0';
		new_ss += strlen(argv[ctr[0]]);
	}
	memset(ss, 0, len);
	_init();
	ret = main(argc, argv);
	_fini();

	exit(ret);
}
