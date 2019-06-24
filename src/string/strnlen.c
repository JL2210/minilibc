#include <string.h>

size_t strnlen(const char *str, size_t len)
{
    size_t ctr = 0;

    while( ctr++ < len && *str++ );

    return --ctr;
}
