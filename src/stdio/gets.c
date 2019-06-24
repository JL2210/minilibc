#include <stdio.h>

char *gets(char *str)
{
    int ch;
    char *tmp = str;

    while( (ch = getchar()) != EOF )
        if(ch == '\n') break;
        else *(tmp++) = ch;

    *tmp = 0;

    return str;
}
