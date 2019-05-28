#include <string.h>

#define uc(x) ((unsigned char)(x))
#define ucp(x) ((unsigned char *)(x))

void *memchr(const void *ptr, int c, size_t len)
{
    size_t ctr;

    for( ctr = 0; ctr < len; ctr++ )
        if( ucp(ptr)[ctr] == uc(c) )
            return (void *)&ucp(ptr)[ctr];

    return NULL;
}
