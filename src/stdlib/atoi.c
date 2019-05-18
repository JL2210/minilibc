#include <stdlib.h>
#include <string.h>

long long atoll(const char *str)
{
    return strtoll(str, NULL, 10);
}
