#include <string.h>

char *strncpy(char *dest, const char *src, size_t len)
{
    char *p = dest;

    while((*p++ = *src++) && len-- > 0);
    while(len-- > 0)
        *p++ = '\0';

    return dest;
}
