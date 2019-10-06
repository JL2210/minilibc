#include <elf.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#ifndef _GENERIC_START
# include "_start.h"
#endif

#if UINTPTR_MAX == 0xffffffffffffffffUL
# define Elf_auxv_t Elf64_auxv_t
#else
# define Elf_auxv_t Elf32_auxv_t
#endif

extern int main(int, char **, char **);

extern void _init(void);
extern void _fini(void);

_Noreturn void _start_c(intptr_t *ptr)
{
    int ret;
    int argc = *ptr;
    Elf_auxv_t *auxv;
    char **argv = (char **)ptr+1;

    __program_invocation_name = *argv;
    __program_invocation_short_name = strrchr(*argv, '/')+1;

    __environ = argv + argc + 1;

    for( ret = 0; __environ[ret]; ret++ )
    {
    }

    auxv = (Elf_auxv_t *)(__environ + ret + 1);

    /* TODO: do something with auxv */
    (void)auxv;

    _init();
    ret = main(argc, argv, __environ);
    _fini();

    exit(ret);
}
