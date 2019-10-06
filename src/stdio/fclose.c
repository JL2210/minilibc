#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fclose(FILE *fp)
{
    int r;
    fflush(fp);
    free(fp->base);
    r = fp->close(fp);
    free(fp);
    return r;
}
