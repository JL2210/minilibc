#include <stdlib.h>
#include <string.h>
#include "libc-deps.h"

long long __atoll(const char *str)
{
    return strtoll(str, NULL, 10);
}

long __atol(const char *str)
{
    return strtol(str, NULL, 10);
}


int (__atoi)(const char *str)
{
    return atol(str);
}

weak_alias(__atoll, atoll);
weak_alias(__atol, atol);
weak_alias(__atoi, atoi);
