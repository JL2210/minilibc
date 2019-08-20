#include <string.h>

char *strncpy(char *dest, const char *src, size_t len)
{
    char *p = dest;

    while( len && (*p++ = *src++) ) len--;
    while( len-- )
        *p++ = '\0';

    return dest;
}
