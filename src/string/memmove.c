#include <string.h>

void *memmove(void *dest, const void *src, size_t len)
{
    const unsigned char *s = src;
    unsigned char *d = dest;
    size_t l;

    if(dest == src)
        goto end;

    /* Check for overlap */
    for( l = 0; l < len; l++ )
    {
        if( s + l == d || s + l == d + len - 1 )
        {
            /* The two objects overlap, so we're allowed to
               use comparison operators. */
            if(s > d)
            {
                /* copy forwards down below */
                break;
            }
            else /* (s < d) */
            {
                /* copy backwards */
                s += len;
                d += len;
                while(len--)
                    *--d = *--s;

                goto end;
            }
        }
    }

    /* They don't overlap or the source is after
       the destination, so just copy forwards */
    while(len--)
        *d++ = *s++;

end:
    return dest;
}
