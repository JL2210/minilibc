#include <string.h>

void *memrchr(const void *ptr, int c, size_t len)
{
    const unsigned char *p = (const unsigned char *)ptr + len;

    while( len && *--p != (unsigned char)c )
    {
        len--;
    }

    return len ? (void *)p : NULL;
}
