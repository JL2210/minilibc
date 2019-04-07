#include <string.h>

void *memchr(const void *ptr, int c, size_t len)
{
    size_t ctr;

    for( ctr = 0; ctr < len; ctr++ )
        if( ((char *)ptr)[ctr] == c ) return (void *)&((char *)ptr)[ctr];

    return NULL;
}
