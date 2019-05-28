#include <string.h>

#define ucp(x) ((unsigned char *)(x))

void *memcpy(void *dest, const void *src, size_t num)
{
    size_t ctr;

    for( ctr = 0; ctr < num; ctr++ )
        (ucp(dest)[ctr] = ucp(src)[ctr];

    return dest;
}
