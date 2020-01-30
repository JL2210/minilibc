#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>

/* fake functions to catch undefined behavior */
int (setjmp)(jmp_buf buf)
{
    fputs("setjmp() macro supressed!\n", stderr);
    abort();
}

int (sigsetjmp)(sigjmp_buf buf)
{
    fputs("sigsetjmp() macro supressed!\n", stderr);
    abort();
}
