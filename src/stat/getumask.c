#include <sys/stat.h>

#include "libc-deps.h"

mode_t getumask(void)
{
    mode_t mask = __umask(0);
    __umask(mask);
    return mask;
}
