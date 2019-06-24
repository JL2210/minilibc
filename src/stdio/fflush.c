#include <stdio.h>
#include <unistd.h>

int fflush(FILE *ostream)
{
    ssize_t size;

    if(!ostream)
        ostream = stdout;

    if(ostream->bufsiz.written)
    {
        ostream->buffer -= ostream->bufsiz.written;
        size = write(fileno(ostream),
                     ostream->buffer,
                     ostream->bufsiz.written);
        if(size == -1) return EOF;
        ostream->bufsiz.size = ostream->bufsiz.orig;
        ostream->bufsiz.written = 0;
    }
    return 0;
}
