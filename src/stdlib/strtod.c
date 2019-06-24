#include <stdlib.h>

double strtod(const char *str, char **endptr)
{
    double decimal, ret = .0;
    char *end = NULL, *endp;

    ret = strtoll(str, &end, 10);
    if(end && *end == '.')
    {
        end++;
        decimal = strtoll(end, &endp, 10);
        while(decimal >= 1.) decimal /= 10.;
        ret += decimal;
        if(endptr) *endptr = endp;
    }
    else
    {
        if(endptr) *endptr = end;
    }

    return ret;
}
