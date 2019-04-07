#include <string.h>

char *strncpy(char *dest, const char *src, size_t len)
{
    size_t ctr;

    for( ctr = 0; ctr < len && src[ctr] != '\0'; ctr++ )
        dest[ctr] = src[ctr];

    for( ; ctr < len; ctr++ )
        dest[ctr] = '\0';

    return dest;
}
