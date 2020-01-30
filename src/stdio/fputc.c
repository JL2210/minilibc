#include <stdio.h>

int fputc(int ic, FILE *stream)
{
    unsigned char c = ic;

    if(!fwrite(&c, 1, 1, stream))
        return EOF;

    return c;
}
