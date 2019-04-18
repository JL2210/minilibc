#include <stdio.h>
#include <unistd.h>

int fgetc(FILE *stream)
{
    int ret = 0;
    read(fileno(stream), &ret, sizeof(char));
    return ret;
}
