#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void *(memcpy)(void *restrict dest, const void *restrict src, size_t len)
{
    const unsigned char *s = src;
    unsigned char *d = dest;
    size_t l;

    /* Check for overlap */
    for( l = 0; l < len; l++ )
    {
        if( s + l == d || s + l == d + len - 1 )
        {
            /* The two objects overlap, so report the error and abort */
            fputs("Overlapping memcpy() detected!\n", stderr);
            abort();
        }
    }

    while(len--)
        *d++ = *s++;

    return dest;
}
