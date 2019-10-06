#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "libc-deps.h"

size_t fread(void *restrict ptr, size_t size, size_t count, FILE *stream)
{
    size_t len;
    ssize_t num_read;
    char *char_buf = ptr;

    if(mul_overflow(count, size, len))
    {
        errno = EINVAL;
        return 0;
    }

    if(*stream->shortbuf)
    {
        *char_buf++ = *stream->shortbuf;
        *stream->shortbuf = 0;
        len--;
    }

    num_read = stream->read(stream, char_buf, len);

    if(num_read == -1) return num_read;
    return num_read == (ssize_t)len ? count : num_read / size;
}
