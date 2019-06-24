#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vfprintf(FILE *fp, const char *fmt, va_list ap)
{
    va_list tmp;
    int size;

    va_copy(tmp, ap);
    size = vsnprintf(NULL, 0, fmt, tmp);
    char result[size];
    memset(result, 0, size);
    vsnprintf(result, size, fmt, ap);
    fputs(result, fp);

    return size;
}
