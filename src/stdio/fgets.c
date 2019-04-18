#include <stdio.h>
#include <unistd.h>

char *fgets(char *str, int len, FILE *stream)
{
    read(fileno(stream), str, len);
    return str;
}
