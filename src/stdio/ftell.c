#include <stdio.h>

long ftell(FILE *fp)
{
    return fp->offset.__ll;
}
