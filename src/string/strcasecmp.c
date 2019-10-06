#include <ctype.h>
#include <strings.h>

int strcasecmp(const char *str1, const char *str2)
{
    const unsigned char *s1 = (const unsigned char *)str1,
                        *s2 = (const unsigned char *)str2;
    while(*s1 && *s2)
    {
        if(toupper(*s1) != toupper(*s2))
            return toupper(*s1) - toupper(*s2);
        s1++; s2++;
    }

    return 0;
}
