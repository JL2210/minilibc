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
            goto terminate;
        }

        *tmp++ = (unsigned char)ch;
    }

terminate:
    *tmp = 0;
    return str;
}
