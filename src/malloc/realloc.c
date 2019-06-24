#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "malloc.h"

#define LESSER(x,y) ((x) > (y) ? (y) : (x))

void *realloc(void *ptr, size_t size)
{
    size_t newsize = 0;
    void *newptr = malloc(size);

    ainfo *allinfo = __allocation_info;

    if(!ptr) goto end;

    while(allinfo->prev)
        allinfo = allinfo->prev;

    while(allinfo->next && allinfo->start != ptr)
        allinfo = allinfo->next;

    if(!allinfo->next)
        return NULL;

    newsize = LESSER(allinfo->size, size);

    memcpy(newptr, ptr, newsize);

end:
    free(ptr);
    return newptr;
}
