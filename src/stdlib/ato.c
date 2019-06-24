#include <stdlib.h>
#include <string.h>

__extension__
long long atoll(const char *str)
{
    return strtoll(str, NULL, 10);
}

long (atol)(const char *str)
{
    return atol(str);
}


int (atoi)(const char *str)
{
    return atoi(str);
}
