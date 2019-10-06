#include <stdlib.h>
#include "libc-deps.h"

void *bsearch(const void *key,
              const void *base,
              size_t nmemb,
              size_t size,
              __compar_fn_t compar)
{
    int cmp;
    char *cbase;

    while(nmemb)
    {
        cbase = (char *)base + size*(nmemb>>1);
        cmp = compar(key, cbase);
        if(!cmp)
        {
            return cbase;
        }
        else if(cmp > 0)
        {
            base = cbase + size;
            nmemb--;
        }
        nmemb >>= 1;
    }

    return NULL;
}
