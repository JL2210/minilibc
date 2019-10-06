#ifndef DECOMPOSE_H
#define DECOMPOSE_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <float.h>

#define MANTISSA_SIZE (DBL_MANT_DIG-1)
#define EXPONENT_SIZE 11
#define EXPONENT_BIAS 0x3ffULL
#define EXPONENT_MASK 0x7ffULL
#define TYPE_MIN DBL_MIN
#define TYPE_MAX DBL_MAX
#define NAME_SFX(name) name
#define NEEDED_ITERS 4

typedef unsigned long long mantissa;
typedef unsigned long long int_rep;
typedef unsigned exponent;
typedef unsigned sign;
typedef double type;

#include "../decompose_generic.h"

#ifdef __cplusplus
}
#endif

#endif
