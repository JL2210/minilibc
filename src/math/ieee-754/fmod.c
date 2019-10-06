#include <math.h>
#include <errno.h>

#include "decompose.h"

type NAME_SFX(fmod)(type x, type y)
{
    if( isnan(x) || isnan(y) )
    {
        return NAME_SFX(nan)("");
    }
    if( y == (type)0 || x > TYPE_MAX || x < TYPE_MIN )
    {
        errno = EDOM;
        return NAME_SFX(nan)("");
    }

    while(x >= y) x -= y;

    return x;
}
