#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>

#include "atexit.h"
#include "libc-deps.h"

static struct atexit list[1], *head = list;

int __at_quick_exit(void (*func)(void))
{
    return __register_atexit_func(&head, func);
}

_Noreturn void __quick_exit(int ret)
{
    __call_atexit_funcs(head);
    _Exit(ret);
}

weak_alias(__at_quick_exit, at_quick_exit);
weak_alias(__quick_exit, quick_exit);
