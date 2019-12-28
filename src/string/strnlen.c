#include <string.h>

size_t strnlen(const char *str, size_t len)
{
    size_t i = 0;

    while( i < len && str[i] )
        i++;

    return i;
}
