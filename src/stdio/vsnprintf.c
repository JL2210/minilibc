#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16
#define BASE_02Z 36

static char *ulltoa(unsigned long long val, char *buf, int base)
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

static size_t nulltoa(unsigned long long val, int base)
{
    size_t size = 0;

    if(base < BASE_BIN)
    {
        errno = EINVAL;
        return 0;
    }

    do {
        size++;
        val /= base;
    } while(val);

    return size;
}

static char *lltoa(long long val, char *buf, int base)
{
    char *s = buf;
    if(val < 0 && base == BASE_DEC)
    {
         val = -val;
         *s++ = '-';
    }

    ulltoa(val, s, base);
    return buf;
}

static size_t nlltoa(long long val, int base)
{
    unsigned char size = 0;

    if(val < 0 && base == BASE_DEC)
    {
        val = -val;
        size++;
    }

    return size + nulltoa(val, base);
}

static
void printf_int_helper
(char **str,
va_list ap,
int base,
char wr,
size_t varsiz,
size_t *written)
{
    long long siz, var;
    if(varsiz <= sizeof(int))
        var = va_arg(ap, int);
    else
        var = va_arg(ap, long long);

    siz = nlltoa(var, base);
    if(wr)
    {
        lltoa(var, *str, base);
        *str += siz;
    }
    *written += siz;
}

static
void printf_uint_helper
(char **str,
va_list ap,
int base,
char wr,
size_t varsiz,
size_t *written)
{
    unsigned long long siz, var;
    if(varsiz <= sizeof(unsigned))
        var = va_arg(ap, unsigned);
    else
        var = va_arg(ap, unsigned long long);

    siz = nulltoa(var, base);
    if(wr)
    {
        ulltoa(var, *str, base);
        *str += siz;
    }
    *written += siz;
}

int vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
    int *n;
    char *s, wr = 1;
    size_t ctr = 0,
           num = 0,
           siz = 0,
           isiz = 0,
           len = strlen(fmt);
    if(!size) wr = 0;
    while(ctr < len)
    {
        while(fmt[ctr] != '%')
        {
            if(wr) *str++ = fmt[ctr];
            ctr++;
            if(ctr >= len)
                goto terminate;
            num++;
        }
        if(++ctr >= len)
        {
            ctr--;
            if(wr) *str++ = fmt[ctr];
            goto terminate;
        }
        isiz = sizeof(int);
check_type:
        switch(fmt[ctr])
        {
        case 'n':
            n = va_arg(ap, int *);
            *n = num;
            break;
        case 'l':
            isiz *= 2;
            /* FALLTHRU */
        case 'h':
            ctr++;
            goto check_type;
        case 'z':
            isiz = sizeof(size_t);
            goto check_type;
        case 'c':
            if(wr) *str++ = va_arg(ap, int);
            num++;
            break;
        case 'd':
        case 'i':
            printf_int_helper(&str, ap, 10, wr, isiz, &num);
            break;
        case 'u':
            printf_uint_helper(&str, ap, 10, wr, isiz, &num);
            break;
        case 'x':
            printf_uint_helper(&str, ap, 16, wr, isiz, &num);
            break;
        case 'p':
            num += 2;
            if(wr)
            {
                memcpy(str, "0x", 2);
                str += 2;
            }
            printf_int_helper(&str, ap, 16, wr, sizeof(void *), &num);
            break;
        case 's':
            s = va_arg(ap, char *);
            siz = strlen(s);
            num += siz;
            if(wr)
            {
                strncpy(str, s, siz);
                str += siz;
            }
            break;
        case '%':
        default:
            if(wr) *str++ = fmt[ctr];
            num++;
            break;
        }
        ctr++;
    }
terminate:
    if(wr) *str = 0;
    return ++num;
}
