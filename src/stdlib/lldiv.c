#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

lldiv_t lldiv(long long numer, long long denom)
{
    lldiv_t result;

    if( (numer == LLONG_MIN && denom == -1) || denom == 0 )
    {
        fputs("Result of lldiv() not representable!\n", stderr);
        abort();
    }

    result.quot = numer / denom;
    result.rem  = numer % denom;

    return result;
}
