#include <string.h>
#include <limits.h>

size_t strlen(const char *str)
{
    const char *s = str;
    while(*str) str++;
    return (size_t)(str - s);
}
