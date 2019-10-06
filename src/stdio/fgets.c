#include <stdio.h>

char *fgets(char *str, int len, FILE *stream)
{
    int ch = 0;
    char *tmp = str;

    while(--len && ch != '\n')
    {
        ch = fgetc(stream);
        if(ch == EOF)
        {
            str = NULL;
            goto ret;
        }
        *tmp++ = (unsigned char)ch;
    }

    *tmp = 0;
ret:
    return str;
}
