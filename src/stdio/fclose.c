#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fclose(FILE *fp)
{
    fflush(fp);
    free(fp->__buffer);
    fsync(fp->__fd);
    close(fp->__fd);
    free(fp);
    return 0;
}
