#include <stdio.h>

int fileno(FILE *fp)
{
    return fp->fd < 0 ? -1 : fp->fd;
}
