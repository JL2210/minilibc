#include <stdio.h>

int fgetc(FILE *stream)
{
    unsigned char c;

    if(!fread(&c, 1, 1, stream))
        return EOF;

    return c;
}
