#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16

#define IS_BETWEEN_A_AND_F(x) (between_a_and_f = (x >= 'a' && x <= 'f'))

long long __strto(const char *str, char **endptr, int base)
{
    int c;
    long long len,
              ctr,
              ret = 0,
              power = 1;
    bool is_negative = false,
         between_a_and_f;

    if(!str) goto invalid;

    while(isspace(*str)) str++;
    if(*str == '-')
    {
        is_negative = true;
        str++;
    }

    len = strlen(str);
    if(!len)
        goto invalid;

    for(ctr = len - 1; ctr >= 0; ctr--, power *= base)
    {
        if(!IS_BETWEEN_A_AND_F(str[ctr]) && !isdigit(str[ctr]))
        {
            if(endptr) *(const char **)endptr = str + ctr;
            break;
        }
        if(!between_a_and_f) c = '0';
        else if(base != 16) goto invalid;
        else c = 'a' - 10;
        ret += (str[ctr] - c) * power;
    }

    return is_negative ? -ret : ret;
invalid:
    errno = EINVAL;
    return 0;
}

long long strtoll(const char *str, char **endptr, int base)
{
    return (long long)__strto(str, endptr, base);
}

unsigned long long strtoull(const char *str, char **endptr, int base)
{
    return (unsigned long long)__strto(str, endptr, base);
}

long strtol(const char *str, char **endptr, int base)
{
    return (long)__strto(str, endptr, base);
}

unsigned long strtoul(const char *str, char **endptr, int base)
{
    return (unsigned long)__strto(str, endptr, base);
}
