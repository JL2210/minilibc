#include <string.h>
#include <stdint.h>

void *memmove(void *dest, const void *src, size_t len)
{
    const unsigned char *s = (const unsigned char *)src;
    unsigned char *d = (unsigned char *)dest;

    /* The most portable this is ever going to get
     * without incurring an O(n) memory penalty
     */
    if((uintptr_t)dest < (uintptr_t)(void *)src)
    {
        while( len-- )
            *d++ = *s++;
    }
    else
    {
        s += len;
        d += len;
        while( len-- )
            *--d = *--s;
    }

    return dest;
}
