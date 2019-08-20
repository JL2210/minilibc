#include <string.h>

void *(memset)(void *ptr, int value, size_t len)
{
    unsigned char *p = (unsigned char *)ptr;

    while( len-- )
        *p++ = (unsigned char)value;

    return ptr;
}
