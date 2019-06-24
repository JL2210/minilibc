#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16
#define BASE_02Z 36

#define GREATER(x,y) ((x) > (y) ? (x) : (y))

static inline int base_str(const char *str)
{
    char greater_base = 0,
         base = 0;
    size_t ctr, len = strlen(str);

    for(ctr = 0; ctr < len && isalnum(str[ctr]); ctr++)
    {
        if(str[ctr] < '0'+BASE_BIN)
            greater_base = BASE_BIN;
        else if(str[ctr] < '0'+BASE_OCT)
            greater_base = BASE_OCT;
        else if(str[ctr] < '0'+BASE_DEC)
            greater_base = BASE_DEC;
        else if(str[ctr] < ('a'-10)+BASE_HEX)
            greater_base = BASE_HEX;
        else if(str[ctr] < ('a'-10)+BASE_02Z)
            greater_base = BASE_02Z;

        base = GREATER(base, greater_base);
    }
    return base;
}

__extension__
long long strtoll(const char *str, char **endptr, int base)
{
    int c;
    __extension__
    long long len,
              ctr,
              ret = 0,
              power = 1;
    char is_negative = 0;

    if(!str) goto invalid;
    while(isspace(*str)) str++;
    if(!(*str)) goto invalid;

    if(*str == '-')
    {
        is_negative = 1;
        str++;
    }
    else if(*str == '+')
    {
        str++;
    }


    if(str[0] == '0')
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
    }
    else if(!base)
    {
        base = BASE_DEC;
    }

    len = strlen(str);
    if(!len)
        goto invalid;

    if(0)
    {
        base = base_str(str);
    }

    for(ctr = 0; ctr < len && isalnum(str[ctr]); ctr++, power *= base);
    if(endptr) *(const char **)endptr = str + ctr;

    power /= base;
    len = ++ctr;

    for(ctr = 0; ctr < len; ctr++, power /= base)
    {
        if(isdigit(str[ctr])) c = '0';
        else c = 'a' - 10;
        ret += (tolower(str[ctr]) - c) * power;
    }

    return is_negative ? -ret : ret;
invalid:
    errno = EINVAL;
    return 0;
}

__extension__
unsigned long long (strtoull)(const char *str, char **endptr, int base)
{
    return strtoull(str, endptr, base);
}

unsigned long (strtoul)(const char *str, char **endptr, int base)
{
    return strtoul(str, endptr, base);
}

long (strtol)(const char *str, char **endptr, int base)
{
    return strtol(str, endptr, base);
}
