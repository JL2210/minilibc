#include <string.h>

char *stpcpy(char *dest, const char *src)
{
    while((*dest = *src++)) dest++;
    return dest;
}
