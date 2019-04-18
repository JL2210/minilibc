#include <stdio.h>
#include <string.h>
#include <unistd.h>

int fputs(const char *str, FILE *stream)
{
    size_t len = strlen(str);
    write(fileno(stream), str, len);
    return len;
}
