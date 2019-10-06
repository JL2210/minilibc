#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>

#include "atexit.h"

static struct atexit list[1], *head = list;

int atexit(void (*func)(void))
{
    return __register_atexit_func(&head, func);
}

_Noreturn void exit(int ret)
{
    __call_atexit_funcs(head);
    fflush(NULL);
    _exit(ret);
}
