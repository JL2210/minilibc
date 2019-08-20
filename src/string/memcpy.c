#include <string.h>
#include "internal/hot.h"

HOT void *(memcpy)(void *restrict dest, const void *restrict src, size_t len)
{
    char *dp = (char *restrict)dest;
    const char *sp = (const char *restrict)src;

    while( len-- )
    {
        *dp++ = *sp++;
    }

    return dest;
}
