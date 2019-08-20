#include <stdio.h>

char *fgets(char *str, int len, FILE *stream)
{
    int ch = 0;
    char *tmp = str;

    while(--len > 0 && ch != '\n')
    {
        ch = fgetc(stream);
        if(ch == EOF)
            goto ret;
        *tmp++ = ch;
    }

    *tmp = 0;
ret:
    return str;
}
