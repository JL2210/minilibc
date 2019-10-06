#include <stdio.h>

int feof(FILE *stream)
{
    return stream->flags & _F_EOF;
}
