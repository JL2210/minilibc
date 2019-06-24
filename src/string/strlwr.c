#include <string.h>
#include <ctype.h>

char *strlwr(char *str)
{
    unsigned char *s = (unsigned char *)str;
    for( ; *s; s++ )
        *s = tolower(*s);
    return str;
}
