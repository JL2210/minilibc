#include <math.h>

#include "decompose.h"

type NAME_SFX(fabs)(type a)
{
    union decompose r = decompose(a);

    r.o.s = 0;

    return r.f;
}
