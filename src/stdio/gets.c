#include <stdio.h>

#include "libc-deps.h"

char *__gets(char *str)
{
    int ch;
    char *tmp = str;

    while( (ch = getchar()) != EOF )
        if(ch == '\n') break;
        else *tmp++ = (unsigned char)ch;

    *tmp = 0;

    return str;
}

weak_alias(__gets, gets);
