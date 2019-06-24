#include <string.h>

char *strcat(char *dest, const char *src)
{
    return strncat(dest, src, strlen(src));
}
