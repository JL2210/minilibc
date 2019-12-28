#include <string.h>

int strncmp(const char *str1, const char *str2, size_t n)
{
    const unsigned char *s1 = str1, *s2 = str2;

    if(str1 == str2)
        return 0;

    while( n && *s1 && *s1 == *s2 )
    {
        s1++;
        s2++;
        n--;
    }

    return *s1 - *s2;
}
