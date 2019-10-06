#include <math.h>
#include <stdlib.h>

#include "decompose.h"

type NAME_SFX(nan)(const char *tag)
{
    union decompose a;
    unsigned long long tag_i = strtoull(tag, NULL, 0);

    a.o.s = 0;
    a.o.e = EXPONENT_MASK;
    a.o.m = tag_i ? tag_i : (mantissa)1 << (MANTISSA_SIZE-1);

    return a.f;
}
