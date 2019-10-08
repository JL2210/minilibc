#include <stdlib.h>

#include "libc-deps.h"

lldiv_t __lldiv(long long numer, long long denom)
{
    lldiv_t result;
    result.quot = numer / denom;
    result.rem  = numer % denom;
    return result;
}

weak_alias(__lldiv, lldiv);
