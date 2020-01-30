#include <stdio.h>
#include <stdlib.h>

int fclose(FILE *fp)
{
    int r;
    fflush(fp);
    r = fp->close(fp);
    free(fp);
    return r;
}
