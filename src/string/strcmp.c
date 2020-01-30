#include <string.h>

#include "libc-deps.h"

int strcmp(const char *str1, const char *str2)
{
    if(str1 == str2)
        return 0;

    while( *str1 && *str1 == *str2 )
    {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

weak_alias(strcmp, strcoll);
