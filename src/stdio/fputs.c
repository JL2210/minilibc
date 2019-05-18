#include <stdio.h>
#include <string.h>
#include <unistd.h>

int fputs(const char *str, FILE *stream)
{
    return write(fileno(stream), str, strlen(str));
}
