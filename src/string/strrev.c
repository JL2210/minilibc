#include <string.h>

char *strrev(char *str)
{
    char tmp, *p1 = str, *p2 = str;
    size_t len = 0;

    while(*p2) p2++, len++;

    --p2;
    len /= 2;

    while( len-- )
    {
        tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
    }
    return str;
}
