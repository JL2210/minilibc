#include <stdio.h>
#include <limits.h>

int vsprintf(char *str, const char *fmt, va_list ap)
{
    return vsnprintf(str, INT_MAX, fmt, ap);
}
