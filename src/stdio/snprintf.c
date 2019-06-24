#include <stdio.h>
#include <stdarg.h>

int snprintf(char *str, size_t size, const char *fmt, ...)
{
    int ret;
    va_list ap;

    va_start(ap, fmt);
    ret = vsnprintf(str, size, fmt, ap);
    va_end(ap);

    return ret;
}
