#include <string.h>

void *memchr(const void *ptr, int c, size_t len)
{
    const unsigned char *s = (const unsigned char *)ptr;

    while( len-- > 0)
        if( *s++ == (unsigned char)c )
            return (void *)--s;

    return NULL;
}
