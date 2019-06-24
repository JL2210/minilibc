#include <string.h>

char *strrev(char *str)
{
    char tmp, *p1 = str, *p2;
    size_t len = strlen(str);

    p2 = str + len - 1;
    len /= 2;

    while( len-- > 0 )
    {
        tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
    }
    return str;
}
