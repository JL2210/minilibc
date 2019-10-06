#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int fflush(FILE *ostream)
{
    int oflags;

    if(!ostream)
        ostream = stdout;

    oflags = (ostream->open_flags & O_RDWR ||
              ostream->open_flags & O_WRONLY);


    if(oflags && ostream->ptr != ostream->base)
    {
        ssize_t size =
               ostream->write(ostream,
                              ostream->base,
                              ostream->ptr - ostream->base);

        if(size == -1) return EOF;

        ostream->ptr = ostream->base;
        __fsync(ostream->fileno);
    }

    return 0;
}
