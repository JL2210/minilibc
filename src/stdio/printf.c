#include <stdio.h>
#include <stdarg.h>

int printf(const char *fmt, ...)
{
    int ret = 0;

    va_list ap;
    va_start(ap, fmt);
    ret = vprintf(fmt, ap);
    va_end(ap);
    return ret;
}
