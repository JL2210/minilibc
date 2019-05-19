#include <string.h>

size_t strnlen(const char *str, size_t len)
{
    size_t ctr;

    for( ctr = 0; ctr < len && str[ctr]; ctr++ );

    return ctr;
}
