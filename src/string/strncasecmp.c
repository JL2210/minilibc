#include <ctype.h>
#include <strings.h>

int strncasecmp(const char *str1, const char *str2, size_t len)
{
    const unsigned char *s1 = str1,
                        *s2 = str2;

    while( len-- && *s1 && tolower(*s1) == tolower(*s2) )
    {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}
