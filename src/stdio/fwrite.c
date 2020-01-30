#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "libc-deps.h"

size_t fwrite(const void *restrict ptr, size_t size, size_t count, FILE *stream)
{
    size_t len;
    ssize_t num_written;

    if(umull_overflow(count, size, &len))
    {
        errno = EINVAL;
        return 0;
    }

    num_written = stream->write(stream, ptr, len);

    if(num_written == -1) return num_written;
    return num_written == (ssize_t)len ? count : num_written / size;
}
