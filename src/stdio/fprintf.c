#include <stdio.h>
#include <stdarg.h>

int fprintf(FILE *stream, const char *fmt, ...)
{
    int ret;
    va_list ap;

    va_start(ap, fmt);
    ret = vfprintf(stream, fmt, ap);
    va_end(ap);

    return ret;
}
