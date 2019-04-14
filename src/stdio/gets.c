#include <stdio.h>

char *gets(char *str)
{
    size_t ctr;
    int ch = '\0';
    for( ctr = 0; ch != '\n' && ch != EOF; ctr++ )
    {
        ch = fgetc(stdin);
        str[ctr] = ch;
    }
    str[--ctr] = '\0';
    return str;
}
