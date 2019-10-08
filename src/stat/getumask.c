#include <sys/stat.h>

#include "libc-deps.h"

mode_t __getumask(void)
{
    mode_t mask = __umask(0);
    __umask(mask);
    return mask;
}

weak_alias(__getumask, getumask);
