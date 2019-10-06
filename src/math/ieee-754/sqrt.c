#include <math.h>
#include <errno.h>

#include "decompose.h"

type NAME_SFX(sqrt)(type a)
{
    union decompose r = decompose(a);
    unsigned int iters = NEEDED_ITERS;

    if(!(a > (type)0))
    {
        if( a == (type)0 || isnan(a) )
            return a;

        errno = EDOM;
        return -NAME_SFX(nan)("");
    }
    if(a > TYPE_MAX)
        return a;

    /* Divide the exponent by 2 */
    r.i = (r.i >> 1) + (EXPONENT_BIAS << (MANTISSA_SIZE-1));

    /* Newton-Raphson */
    while(iters--)
        r.f = (r.f + a/r.f)/2;

    return r.f;
}
