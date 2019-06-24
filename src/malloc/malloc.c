#include <stdlib.h>
#include <unistd.h>

#include "malloc.h"

void *malloc(size_t size)
{
    if(__get_next_allocation(size))
        return NULL;
    return __allocation_info->start;
}
