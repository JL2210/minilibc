#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static ssize_t vsn_write(FILE *fp, const void *buf, size_t cnt)
{
    /* bytes to write */
    size_t towr = fp->end - fp->ptr;

    if(towr > cnt)
        towr = cnt;

    memcpy(fp->ptr, buf, towr);
    fp->ptr += towr;

    return cnt;
}

int vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
    int ret;
    FILE fp[1];

    /* Don't overwrite str if passed SIZE_MAX
       from unbounded library functions */
    if(size > SIZE_MAX - (size_t)str - 1)
        size = SIZE_MAX - (size_t)str - 1;

    fp->base = fp->ptr = (unsigned char *)str;
    fp->end = fp->base + size;
    fp->write = vsn_write;

    ret = vfprintf(fp, fmt, ap);

    if(size)
        fp->ptr[-(fp->ptr == fp->end)] = 0;

    return ret;
}
