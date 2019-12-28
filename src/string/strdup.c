#include <string.h>
#include <stdlib.h>

char *strdup(const char *str)
{
    size_t len = strlen(str) + 1;
    char *dest = malloc(len);

    if(dest)
        memcpy(dest, str, len);

    return dest;
}
