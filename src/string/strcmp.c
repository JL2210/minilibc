#include <string.h>

#include "libc-deps.h"

int strcmp(const char *str1, const char *str2)
{
    const unsigned char *s1 = str1, *s2 = str2;

    if(str1 == str2)
        return 0;

    while( *s1 && *s1 == *s2 )
    {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

weak_alias(strcmp, strcoll);
