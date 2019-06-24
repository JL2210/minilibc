#include <string.h>
#include <limits.h>

size_t strlen(const char *str)
{
    return strnlen(str, SSIZE_MAX);
}
