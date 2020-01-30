#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

int sprintf(char *str, const char *fmt, ...)
{
    int ret;
    va_list ap;

    va_start(ap, fmt);
    ret = vsnprintf(str, SIZE_MAX, fmt, ap);
    va_end(ap);

    return ret;
}
