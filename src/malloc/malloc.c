#include <stdlib.h>
#include <unistd.h>

#include "malloc.h"

void *malloc(size_t size)
{
    __get_next_allocation(size);
    return __allocinfo->start;
}
