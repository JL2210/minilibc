#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fflush(FILE *ostream)
{
    if(!ostream)
        /* TODO: flush all output streams */
        ostream = stdout;

    if((ostream->open_flags & O_RDWR ||
        ostream->open_flags & O_WRONLY) &&
        ostream->ptr != ostream->base)
    {
        ssize_t size =
          ostream->write(ostream,
                         ostream->base,
                         ostream->ptr - ostream->base);

        if(size == -1)
            return EOF;

        ostream->ptr = ostream->base;
        __fsync(ostream->fileno);
    }
    else if(ostream->open_flags & O_RDONLY)
    {
        fputs("Error: trying to fflush input stream\n", stderr);
        abort();
    }

    return 0;
}
