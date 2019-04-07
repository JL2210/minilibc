#include <string.h>

size_t strlen(const char *str)
{
    size_t ctr;

    for( ctr = 0; str[ctr]; ctr++ );

    return ctr;
}
