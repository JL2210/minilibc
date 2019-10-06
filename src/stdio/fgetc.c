#include <stdio.h>

int fgetc(FILE *stream)
{
    int ret;

    if(!fread(&ret, 1, 1, stream))
        ret = EOF;

    return ret;
}
