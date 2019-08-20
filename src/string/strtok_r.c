#include <string.h>

char *strtok_r(char *str, const char *delim, char **saveptr)
{
    if(!str && !(str = *saveptr)) return NULL;
    str += strspn(str, delim);
    if(!*str) return *saveptr = NULL;
    *saveptr = str + strcspn(str, delim);
    if(**saveptr) *(*saveptr)++ = 0;
    else *saveptr = 0;
    return str;
}
