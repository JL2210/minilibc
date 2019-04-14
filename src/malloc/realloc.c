#include "malloc.h"

#include <stdlib.h>
#include <string.h>

void *realloc(void *ptr, size_t size)
{
    size_t newsize = 0;
    void *newptr = malloc(size);

    struct allocation_info *tmp_allinfo = __allocinfo;

    if(!ptr) return newptr;

    while(tmp_allinfo->prev != NULL)
        tmp_allinfo = tmp_allinfo->prev;

    while(tmp_allinfo && tmp_allinfo->start != ptr)
        tmp_allinfo = tmp_allinfo->next;

    if(!tmp_allinfo) return NULL;

    if(tmp_allinfo->size > size)
        newsize = size;
    else
        newsize = tmp_allinfo->size;

    memcpy(newptr, ptr, newsize);
    tmp_allinfo->free = 1;

    return newptr;
}
