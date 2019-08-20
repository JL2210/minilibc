#include <stdio.h>

int ungetc(int c, FILE *stream)
{
    return stream->__unget = c;
}
