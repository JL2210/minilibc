#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static ssize_t vsn_write(FILE *fp, const void *buf, size_t cnt)
{
    size_t towr = fp->end - fp->ptr;
    if(towr > cnt) towr = cnt;

    memcpy(fp->ptr, buf, towr);
    fp->ptr += towr;
    return cnt;
}

int vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
    int ret;
    FILE fp[1];

    if(size > SIZE_MAX - (size_t)str - 1)
        size = SIZE_MAX - (size_t)str - 1;

    fp->base = fp->ptr = str;
    fp->end = str + size;
    fp->write = vsn_write;

    ret = vfprintf(fp, fmt, ap);

    if(size) fp->ptr[-(fp->ptr == fp->end)] = 0;

    return ret;
}
