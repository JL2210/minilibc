#include <elf.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include "_start.h"

#if UINTPTR_MAX == 0xffffffffffffffffUL
# define Elf_auxv_t Elf64_auxv_t
#else
# define Elf_auxv_t Elf32_auxv_t
#endif

#define AUX_NUM 38

extern int main();

#ifdef __cplusplus
extern "C" {
#endif

_Noreturn int __libc_start_main
(
int (*main)(),
int,
char **
);

extern void _init(void);
extern void _fini(void);

_Noreturn void _c_start(intptr_t *ptr)
{
    int argc = *ptr;
    char **argv = (char **)ptr+1;

    __libc_start_main(main, argc, argv);
}

_Noreturn int __libc_start_main
(
int (*__main)(),
int argc,
char **argv
)
{
    int ret;
    Elf_auxv_t *auxv;
    /* Do some f*cking around with function names
     * to make g++ and clang++ happy
     */
    int (*_main)(int, char **, char **, Elf_auxv_t *) = (int (*)(int, char **, char **, Elf_auxv_t *))((void *)__main);

    program_invocation_name = *argv;
    program_invocation_short_name = strrchr(*argv, '/') + 1;

    environ = argv + argc + 1;

    for( ret = 0; environ[ret]; ret++ );

    auxv = (Elf_auxv_t *)(environ + ret + 1);

    _init();
    ret = _main(argc, argv, environ, auxv);
    _fini();

    exit(ret);
}

#ifdef __cplusplus
}
#endif
