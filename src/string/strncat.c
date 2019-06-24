#include <string.h>

char *strncat(char *dest, const char *src, size_t len)
{
    size_t dlen = strlen(dest);

    len = strnlen(src, len);

    memcpy((void *)(dest + dlen), (void *)src, len);
    *(dest + dlen + len) = 0;

    return dest;
}
