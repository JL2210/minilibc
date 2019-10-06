#include <stdio.h>

void clearerr(FILE *stream)
{
    stream->flags &= ~(_F_EOF | _F_ERR);
}
