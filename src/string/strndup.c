#include <string.h>
#include <stdlib.h>

char *strndup(const char *str, size_t len)
{
    return strncpy((char *)malloc(strnlen(str, len)+1), str, len);
}
