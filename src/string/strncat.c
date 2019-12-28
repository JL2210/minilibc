#include <string.h>

char *strncat(char *dest, const char *src, size_t len)
{
    char *d = dest + strlen(dest);

    while( len && *src )
    {
        len--;
        *d++ = *src++;
    }
    *d = 0;

    return dest;
}
