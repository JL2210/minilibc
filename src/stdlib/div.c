#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

div_t div(int numer, int denom)
{
    div_t result;

    if( (numer == INT_MIN && denom == -1) || denom == 0 )
    {
        fputs("Result of div() not representable!\n", stderr);
        abort();
    }

    result.quot = numer / denom;
    result.rem  = numer % denom;

    return result;
}
