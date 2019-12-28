#include <string.h>

#include "libc-deps.h"

char *__stpcpy(char *dest, const char *src)
{
    while((*dest = *src++))
        dest++;

    return dest;
}

weak_alias(__stpcpy, stpcpy);
