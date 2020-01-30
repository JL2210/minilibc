#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int vsprintf(char *str, const char *fmt, va_list ap)
{
    return vsnprintf(str, SIZE_MAX, fmt, ap);
}
