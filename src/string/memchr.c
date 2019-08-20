#include <string.h>

void *(memchr)(const void *ptr, int c, size_t len)
{
    const unsigned char *s = (const unsigned char *)ptr;

    while( len-- )
    {
        if( *s == (unsigned char)c )
            return (void *)s;
        s++;
    }

    return NULL;
}
