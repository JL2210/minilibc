#include <stdlib.h>
#include <elf.h>

#include "_start.h"

extern _Noreturn int __libc_start_main
(
int (*main)(),
int,
char **
);

extern int main();

#ifdef __cplusplus
extern "C"
#endif
_Noreturn void _c_start(long *ptr)
{
    int argc = *ptr;
    char **argv = (char **)ptr+1;

    __libc_start_main(main, argc, argv);
}
