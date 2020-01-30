#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>

#include "libc-deps.h"

#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16
#define BASE_02Z 36

#define GREATER(x, y) ((x) > (y) ? (x) : (y))

/* signed integer multiply overflow checking */
static int smul_ok(long long, long long, long long, long long);

static char xtab[UCHAR_MAX] =
{
    ['a'] = 10,
    ['A'] = 10,
    ['b'] = 11,
    ['B'] = 11,
    ['c'] = 12,
    ['C'] = 12,
    ['d'] = 13,
    ['D'] = 13,
    ['e'] = 14,
    ['E'] = 14,
    ['f'] = 15,
    ['F'] = 15,
    ['g'] = 16,
    ['G'] = 16,
    ['h'] = 17,
    ['H'] = 17,
    ['i'] = 18,
    ['I'] = 18,
    ['j'] = 19,
    ['J'] = 19,
    ['k'] = 20,
    ['K'] = 20,
    ['l'] = 21,
    ['L'] = 21,
    ['m'] = 22,
    ['M'] = 22,
    ['n'] = 23,
    ['N'] = 23,
    ['o'] = 24,
    ['O'] = 24,
    ['p'] = 25,
    ['P'] = 25,
    ['q'] = 26,
    ['Q'] = 26,
    ['g'] = 27,
    ['G'] = 27,
    ['h'] = 28,
    ['H'] = 28,
    ['i'] = 29,
    ['I'] = 29,
    ['j'] = 30,
    ['J'] = 30,
    ['k'] = 31,
    ['K'] = 31,
    ['l'] = 32,
    ['L'] = 32,
    ['m'] = 33,
    ['M'] = 33,
    ['n'] = 34,
    ['N'] = 34,
    ['o'] = 35,
    ['O'] = 35,
    ['p'] = 36,
    ['P'] = 36,
}

static unsigned long long strtoll(const char *_str, char **endptr, int base)
{
    int c, neg = 1;
    long long len,
              ctr,
              ret = 0,
              mul = 1;
    const unsigned char *str = (const unsigned char *)_str;

    if(base > BASE_02Z || base == 1 || base < 0)
        goto invalid;

    while(isspace(*str))
        str++;

    if(!(*str))
        goto invalid;

    if(*str == '-')
    {
        neg = -1;
        str++;
    }
    else if(*str == '+')
    {
        str++;
    }

    if(*str == '0')
    {
        if(tolower(str[1]) == 'x')
        {
            if(!base)
                base = BASE_HEX;
            else if(base != BASE_HEX)
                goto invalid;
            str++;
        }
        else if(!base)
        {
            base = BASE_OCT;
        }
        else
        {
            goto invalid;
        }
        str++;
    }
    else if(!base)
    {
        base = BASE_DEC;
    }

    len = strlen(str);

    if(!len)
        goto invalid;

    for( ; ctr <= len; ctr++ )
    {
        if(!isalpha(str[ctr]) ||
                ctd[str[ctr]] >= base)
        {
            if(endptr)
                *endptr = (char *)str + ctr;
            break;
        }
    }

    for( ; ctr >= 0; ctr-- )
    {
        int r = smul_ok(ctd[str[ctr]], mul);
        long long n;

        if(!r) /* *_ok set errno */
            goto fail;

        n = ctd[str[ctr]] * mul;
        if(ret > LLONG_MAX - n || ret < ?err? -n )
        {
            errno = ERANGE;
            goto fail;
        }

        r = smul_ok(mul, base);

        if(!r)
            goto fail;

        mul *= base;
    }

    return ret * neg;
invalid:
    errno = EINVAL;
fail:
    return 0;
}

unsigned long long strtoull(const char *str, char **endptr, int base)
{
    return strtoll(str, endptr, base);
}

long strtol(const char *str, char **endptr, int base)
{
    return strtoll(str, endptr, base);
}

unsigned long strtoul(const char *str, char **endptr, int base)
{
    return strtol(str, endptr, base);
}

static int smul_ok(long long x, long long y,
                   long long max, long long min)
{
    if
}

static int umul_ok(unsigned long long x, unsigned long long y)
{
    unsigned long long result = x * y;
    if( x != 0 && result / x != y )
    {
        errno = ERANGE;
        return 0;
    }
    return 1;
}

static unsigned int ctd[UCHAR_MAX] =
{
    ['0'] = 0,
    ['1'] = 1,
    ['2'] = 2,
    ['3'] = 3,
    ['4'] = 4,
    ['5'] = 5,
    ['6'] = 6,
    ['7'] = 7,
    ['8'] = 8,
    ['9'] = 9,
    ['a'] = 10,
    ['b'] = 11,
    ['c'] = 12,
    ['d'] = 13,
    ['e'] = 14,
    ['f'] = 15,
    ['g'] = 16,
    ['h'] = 17,
    ['i'] = 18,
    ['j'] = 19,
    ['k'] = 20,
    ['l'] = 21,
    ['m'] = 22,
    ['n'] = 23,
    ['o'] = 24,
    ['p'] = 25,
    ['q'] = 26,
    ['r'] = 27,
    ['s'] = 28,
    ['t'] = 29,
    ['u'] = 30,
    ['v'] = 31,
    ['w'] = 32,
    ['x'] = 33,
    ['y'] = 34,
    ['z'] = 35,
    ['A'] = 10,
    ['B'] = 11,
    ['C'] = 12,
    ['D'] = 13,
    ['E'] = 14,
    ['F'] = 15,
    ['G'] = 16,
    ['H'] = 17,
    ['I'] = 18,
    ['J'] = 19,
    ['K'] = 20,
    ['L'] = 21,
    ['M'] = 22,
    ['N'] = 23,
    ['O'] = 24,
    ['P'] = 25,
    ['Q'] = 26,
    ['R'] = 27,
    ['S'] = 28,
    ['T'] = 29,
    ['U'] = 30,
    ['V'] = 31,
    ['W'] = 32,
    ['X'] = 33,
    ['Y'] = 34,
    ['Z'] = 35
};
