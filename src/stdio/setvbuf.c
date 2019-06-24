#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int setvbuf(FILE *stream, char *buf, int type, size_t size)
{
    if(type && !(type & __STDIO_BUFFERED))
    {
        errno = EINVAL;
        return -1;
    }
    if(buf)
    {
        stream->buffer = buf;
        stream->bufsiz.size = stream->bufsiz.orig = size;
        stream->bufsiz.written = 0;
    }
    stream->flags = (stream->flags & __IO_BF_MASK) | type;
    return 0;
}
