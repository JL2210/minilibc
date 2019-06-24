#include <string.h>

void *memrchr(const void *ptr, int c, size_t len)
{
    const unsigned char *p = (const unsigned char *)ptr + len - 1;

    while( len-- > 0 )
        if( *p-- == (unsigned char)c )
            return (void *)++p;

    return NULL;
}
