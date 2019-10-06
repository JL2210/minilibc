#include <string.h>
#include <stdint.h>
#include "libc-deps.h"

#define ALIGNED(x) !((uintptr_t)(x) & (sizeof(size_t)-1))

void *(memcpy)(void *restrict dest, const void *restrict src, size_t len)
{
    while( len-- )
    {
        unsigned char *restrict dp = dest;
        const unsigned char *restrict sp = src;
        *dp++ = *sp++;
    }

    return dest;
}
