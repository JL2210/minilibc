#include <string.h>

void *(memcpy)(void *restrict dest, const void *restrict src, size_t len)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if(dest == src)
        goto end;

    while(len--)
        *d++ = *s++;

end:
    return dest;
}
