#include <stdio.h>

int feof(FILE *stream)
{
    return stream->__flags & __STDIO_EOF;
}
