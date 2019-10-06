#include <stdio.h>

int fseek(FILE *fp, long off, int whence)
{
    return fp->seek(fp, off, whence);
}
