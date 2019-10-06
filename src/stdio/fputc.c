#include <stdio.h>

int fputc(int c, FILE *stream)
{
    if(!fwrite(&c, 1, 1, stream))
        c = EOF;

    return c;
}
