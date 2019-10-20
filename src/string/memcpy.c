#include <string.h>
#include <stdint.h>

void *(memcpy)(void *restrict dest, const void *restrict src, size_t len)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    while( len-- )
        *d++ = *s++;

    return dest;
}
