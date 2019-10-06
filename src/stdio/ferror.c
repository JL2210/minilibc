#include <stdio.h>

int ferror(FILE *stream)
{
    return stream->flags & _F_ERR;
}
