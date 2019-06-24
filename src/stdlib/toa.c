#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16
#define BASE_02Z 36

__extension__
char *ulltoa(unsigned long long val, char *buf, int base)
{
    int remainder;
    char c, *tmp = buf;

    if(base < BASE_BIN)
    {
        errno = EINVAL;
        return NULL;
    }

    do {
        remainder = val % base;
        if(remainder >= BASE_DEC) c = 'a' - BASE_DEC;
        else c = '0';
        *tmp++ = remainder + c;
        val /= base;
    } while(val);

    *tmp = 0;
    return strrev(buf);
}

__extension__
size_t nulltoa(unsigned long long val, int base)
{
    size_t size = 0;

    if(base < BASE_BIN)
    {
        errno = EINVAL;
        return 0;
    }

    if(!val) size++;

    for( ; val; val /= base, size++ );

    return size;
}

__extension__
char *lltoa(long long val, char *buf, int base)
{
    if(val < 0 && base > BASE_BIN)
    {
         val = -val;
         *buf++ = '-';
    }

    return ulltoa(val, buf, base);
}

__extension__
size_t nlltoa(long long val, int base)
{
    size_t size = 0;

    if(val < 0 && base > BASE_BIN)
    {
        val = -val;
        size++;
    }

    return size + nulltoa(val, base);
}
