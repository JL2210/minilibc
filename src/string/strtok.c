#include <string.h>

static char *saveptr;

char *strtok(char *str, const char *delim)
{
    return strtok_r(str, delim, &saveptr);
}
