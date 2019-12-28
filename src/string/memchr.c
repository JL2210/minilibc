#include <string.h>

void *(memchr)(const void *ptr, int c, size_t len)
{
    const unsigned char *s = ptr;

    while( len && *s != (unsigned char)c )
    {
        s++;
        len--;
    }

    return len ? (void *)s : NULL;
}
