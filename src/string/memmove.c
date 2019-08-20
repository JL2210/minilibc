#include <string.h>

void *memmove(void *dest, const void *src, size_t len)
{
    const char *s = (const char *)src;
    char *d = (char *)dest;

    if(d < s)
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
