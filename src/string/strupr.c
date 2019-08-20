#include <ctype.h>
#include <string.h>

char *strupr(char *str)
{
    unsigned char *s = (unsigned char *)str;
    for( ; *s; s++ )
        *s = toupper(*s);
    return str;
}
