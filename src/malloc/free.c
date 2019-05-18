#include "malloc.h"

#include <stdlib.h>
#include <string.h>

void free(void *ptr)
{
    struct allocation_info *tmp_allinfo = __allocinfo;

    if(!ptr) return;

    while(tmp_allinfo->prev != NULL)
        tmp_allinfo = tmp_allinfo->prev;

    while(tmp_allinfo && tmp_allinfo->start != ptr)
        tmp_allinfo = tmp_allinfo->next;

    if(!tmp_allinfo) return;

    memset(tmp_allinfo->start, 0, tmp_allinfo->size);
    tmp_allinfo->free = 1;
}
