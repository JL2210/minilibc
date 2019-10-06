#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int setvbuf(FILE *stream, char *buf, int type, size_t size)
{
    if(type & ~(_F_NBF | _F_LBF | _F_FBF))
    {
        errno = EINVAL;
        return -1;
    }

    if(buf)
    {
        stream->base = stream->ptr = buf;
        stream->end = buf + size;
    }
    else
    {
        if(size)
            buf = malloc(size);
        stream->base = stream->ptr = buf;
        stream->end = buf + size;
    }

    stream->flags &= ~(_F_NBF | _F_LBF | _F_FBF);
    stream->flags |= type;
    return 0;
}
