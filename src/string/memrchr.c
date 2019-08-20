#include <string.h>

void *memrchr(const void *ptr, int c, size_t len)
{
    const unsigned char *p = (const unsigned char *)ptr + len - 1;

    while( len-- )
    {
        if( *p == (unsigned char)c )
            return (void *)p;
        p--;
    }

    return NULL;
}
