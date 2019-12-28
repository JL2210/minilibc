#include <ctype.h>
#include <strings.h>

int strcasecmp(const char *str1, const char *str2)
{
    const unsigned char *s1 = str1, *s2 = str2;

    if(str1 == str2)
        return 0;

    while( *s1 && toupper(*s1) == toupper(*s2) )
    {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}
