#include <string.h>

void *memcpy(void *dest, const void *src, size_t num)
{
    const unsigned char *s = (const unsigned char *)src;
    unsigned char *d = (unsigned char *)dest;

    while( num-- > 0 )
        *d++ = *s++;

    return dest;
}
