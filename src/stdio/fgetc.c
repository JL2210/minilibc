#include <stdio.h>
#include <unistd.h>

int fgetc(FILE *stream)
{
    int ret = 0;
    read(stream->fd, &ret, sizeof(char));
    return ret;
}
