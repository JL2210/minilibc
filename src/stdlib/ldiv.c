#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

ldiv_t ldiv(long numer, long denom)
{
    ldiv_t result;

    if( (numer == LONG_MIN && denom == -1) || denom == 0 )
    {
        fputs("Result of ldiv() not representable!\n", stderr);
        abort();
    }

    result.quot = numer / denom;
    result.rem  = numer % denom;

    return result;
}
