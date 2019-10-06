#include <string.h>

int strcmp(const char *str1, const char *str2)
{
    const unsigned char *s1 = (const unsigned char *)str1,
                        *s2 = (const unsigned char *)str2;

    while(*s1 && *s2)
    {
        if(*s1 != *s2)
            return *s1 - *s2;
        s1++; s2++;
    }

    return 0;
}
