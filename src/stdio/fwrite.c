#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static inline
ssize_t write_to_buf(FILE *stream, const void *p, size_t size)
{
    char *buf;
    size_t sz;

    if(stream->flags & __STDIO_BUFFERED)
    {
        if(!stream->buffer)
        {
            sz = size > BUFSIZ ? size : BUFSIZ;
            buf = (char *)malloc(sz);
            setvbuf(stream, buf, _IOFBF, sz);
        }
get_size:
        if(stream->bufsiz.size < size)
        {
            fflush(stream);
            goto get_size;
        }
        memcpy(stream->buffer, p, size);
        stream->bufsiz.size -= size;
        stream->bufsiz.written += size;
        stream->buffer += size;
    }
    else
    {
        if(write(fileno(stream), p, size) == -1)
            return -1;
    }
    stream->fpos.offset += size;
    return size;
}

size_t fwrite(const void *p, size_t size, size_t count, FILE *stream)
{
    size_t ctr = 0;
    while( ctr++ < count )
    {
        if(write_to_buf(stream, p, size) == -1)
            break;
        p = (const char *)p + size;
    }
    return --ctr;
}
