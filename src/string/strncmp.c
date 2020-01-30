#include <string.h>

int strncmp(const char *str1, const char *str2, size_t n)
{
    if(str1 == str2)
        return 0;

    while( n && *str1 && *str1 == *str2 )
    {
        str1++;
        str2++;
        n--;
    }

    return *str1 - *str2;
}
