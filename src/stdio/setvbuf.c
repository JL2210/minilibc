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
        stream->__buffer = buf;
        stream->__bufsiz.__size = stream->__bufsiz.__orig = size;
        stream->__bufsiz.__written = 0;
    }
    stream->__flags = (stream->__flags & __IO_BF_MASK) | type;
    return 0;
}
