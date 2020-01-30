#include <stdio.h>

__attribute__((__deprecated__))
char *gets(char *str)
{
    int ch;
    char *tmp = str;

    while((ch = getchar()) != EOF)
    {
        if(ch == '\n')
            break;
        else
            *tmp++ = (unsigned char)ch;
    }

    *tmp = 0;

    return str;
}
