#include <stdlib.h>
#include <string.h>

long long atoll(const char *str)
{
    return strtoll(str, NULL, 10);
}

long atol(const char *str)
{
    return strtol(str, NULL, 10);
}

int atoi(const char *str)
{
    return (int)atol(str);
}
