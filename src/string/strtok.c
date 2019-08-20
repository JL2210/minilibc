#include <string.h>

char *strtok(char *str, const char *delim)
{
    static char *saveptr;
    return strtok_r(str, delim, &saveptr);
}
