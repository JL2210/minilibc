#include <stdlib.h>
#include <string.h>

#include "malloc.h"

void free(void *ptr)
{
    ainfo *allinfo = __allocation_info;

    if(!ptr) return;

    while(allinfo->prev)
        allinfo = allinfo->prev;

    while(allinfo->next && allinfo->start != ptr)
        allinfo = allinfo->next;

    if(!allinfo->next) return;

    memset(allinfo->start, 0, allinfo->size);
    allinfo->free = 1;
}
