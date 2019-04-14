#include <string.h>

void *memchr(const void *ptr, int c, size_t len)
{
    size_t ctr;

    c = (unsigned char)c;

    for( ctr = 0; ctr < len; ctr++ )
        if( ((unsigned char *)ptr)[ctr] == c )
            return (void *)&((unsigned char *)ptr)[ctr];

    return NULL;
}
