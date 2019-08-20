#include <string.h>

char *strncat(char *dest, const char *src, size_t len)
{
    char *d = dest;

    while(*d) d++;
    while( len-- && (*d++ = *src++) );

    return dest;
}
