#include <stdnoreturn.h>
#include <stdlib.h>
#include <elf.h>

#include "_start.h"

#ifndef NEWBOOT_H

extern _Noreturn int __libc_start_main
(
int (*)(int, char**, char**),
int,
char **
);
extern int main(int, char**, char**);

void _c_start(intptr_t *ptr)
{
    int argc = *ptr;
    char **argv = (char **)ptr+1;

    __libc_start_main(main, argc, argv);
}

#endif
