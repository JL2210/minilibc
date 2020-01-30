#include <stdio.h>

int ungetc(int c, FILE *stream)
{
    if(!stream->ungetp || !stream->unget ||
       c == EOF || stream->unget >= stream->unget_max)
        return EOF;

    stream->ungetp[stream->unget++] = c;

    return c;
}
