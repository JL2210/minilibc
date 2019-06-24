#include <stdio.h>
#include <unistd.h>

int fgetc(FILE *stream)
{
    int ret;
/*  fread(&ret, 1, 1, stream); */
    read(fileno(stream), &ret, 1);
    return ret;
}
