#include <stdio.h>

void clearerr(FILE *stream)
{
    stream->__flags &= ~(__STDIO_EOF);
}
