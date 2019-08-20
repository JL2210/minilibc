#include <stdio.h>

int fileno(FILE *fp)
{
    return fp->__fd < 0 ? -1 : fp->__fd;
}
