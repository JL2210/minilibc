#include <string.h>
#include <limits.h>

char *strcpy(char *dest, const char *src)
{
    return strncpy(dest, src, SSIZE_MAX);
}
