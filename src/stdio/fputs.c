#include <stdio.h>
#include <string.h>
#include <unistd.h>

int fputs(const char *str, FILE *stream)
{
    int len = strlen(str);
    fwrite(str, len, 1, stream);
    return len;
}
