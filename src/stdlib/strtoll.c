#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "libc-deps.h"

#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16
#define BASE_02Z 36

#define GREATER(x, y) ((x) > (y) ? (x) : (y))

long long strtoll(const char *str, char **endptr, int base)
{
    int c, neg = 1;
    long long len,
              ctr,
              ret = 0,
              power = 1;

    if(base > BASE_02Z) goto invalid;

    while(isspace(*str)) str++;
    if(!(*str)) goto invalid;

    if(*str == '-' || *str == '+')
    {
        neg = -(*str == '-');
        str++;
    }


    if(*str == '0')
    {
        if(tolower(str[1]) == 'x')
        {
            if(!base) base = BASE_HEX;
            else if(base != BASE_HEX) goto invalid;
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
    }
    else if(!base)
    {
        base = BASE_DEC;
    }

    len = strlen(str);
    if(!len)
        goto invalid;

    for( ctr = 0; ctr < len && isalnum(str[ctr]); ctr++ ) power *= base;
    if(endptr) *(const char **)endptr = str + ctr;

    len = ctr;

    for( ctr = 0; ctr <= len; ctr++, power /= base )
    {
        if(isdigit(str[ctr])) c = '0';
        else c = 'a' - 10;
        ret += (tolower(str[ctr]) - c) * power;
    }

    return ret*neg;
invalid:
    errno = EINVAL;
    return 0;
}

unsigned long long (strtoull)(const char *str, char **endptr, int base)
{
    return strtoll(str, endptr, base);
}

long (strtol)(const char *str, char **endptr, int base)
{
    return strtoll(str, endptr, base);
}

unsigned long (strtoul)(const char *str, char **endptr, int base)
{
    return strtol(str, endptr, base);
}
