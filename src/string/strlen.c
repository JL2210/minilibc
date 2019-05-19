#include <string.h>

size_t strlen(const char *str)
{
    return strnlen(str, SIZE_MAX);
}
