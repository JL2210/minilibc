#include <stdio.h>

int ungetc(int c, FILE *stream)
{
    return *stream->shortbuf = (unsigned char)c;
}
