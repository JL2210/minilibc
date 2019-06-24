#include <elf.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#if UINTPTR_MAX == 0xffffffffffffffffUL
# define Elf_auxv_t Elf64_auxv_t
#else
# define Elf_auxv_t Elf32_auxv_t
#endif

#ifdef __cplusplus
extern "C" {
#endif
void _init(void);
void _fini(void);
#ifdef __cplusplus
}
#endif

#define AUX_NUM 38

_Noreturn int __libc_start_main
(
int (*___main)(),
int argc,
char **argv
)
{
    int ret;
    Elf_auxv_t *auxv;
    size_t aux[AUX_NUM];
    /* Do some f*cking around with function names
     * to make g++ and clang++ happy
     */
    void *__main = (void *)___main;
    int (*_main)(int, char **, char **, size_t *) = (int (*)(int, char **, char **, size_t *))__main;

    program_invocation_name = *argv;
    program_invocation_short_name = strrchr(*argv, '/') + 1;
    environ = argv + argc + 1;

    for( ret = 0; environ[ret]; ret++ );

    auxv = (Elf_auxv_t *)(environ + ret + 1);

    for( ret = 0; ret < AUX_NUM; ret++ )
        aux[ret] = auxv[ret].a_un.a_val;

    _init();
    ret = _main(argc, argv, environ, aux);
    _fini();

    exit(ret);
}
