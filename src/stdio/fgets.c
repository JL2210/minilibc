#include <stdio.h>
#include <unistd.h>

char *fgets(char *str, int len, FILE *stream)
{
    read(stream->fd, str, len);
    return str;
}
