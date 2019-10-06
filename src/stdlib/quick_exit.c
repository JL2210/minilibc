#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>

#include "atexit.h"

static struct atexit list[1], *head = list;

int at_quick_exit(void (*func)(void))
{
    return __register_atexit_func(&head, func);
}

_Noreturn void quick_exit(int ret)
{
    __call_atexit_funcs(head);
    _Exit(ret);
}
