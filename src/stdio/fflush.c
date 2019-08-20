#include <stdio.h>
#include <unistd.h>

int fflush(FILE *ostream)
{
    if(!ostream)
        ostream = stdout;

    if(ostream->__bufsiz.__written)
    {
        ssize_t size;
        int fd = fileno(ostream);
        ostream->__buffer -= ostream->__bufsiz.__written;
        size = write(fd,
                     ostream->__buffer,
                     ostream->__bufsiz.__written);
        if(size == -1) return EOF;
        ostream->__bufsiz.__size = ostream->__bufsiz.__orig;
        ostream->__bufsiz.__written = 0;
        fsync(fd);
    }
    return 0;
}
