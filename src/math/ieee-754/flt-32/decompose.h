#ifndef DECOMPOSE_H
#define DECOMPOSE_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <float.h>

#define MANTISSA_SIZE (FLT_MANT_DIG-1)
#define EXPONENT_SIZE 8
#define EXPONENT_BIAS 0x7f
#define EXPONENT_MASK 0xff
#define TYPE_MIN FLT_MIN
#define TYPE_MAX FLT_MAX
#define NAME_SFX(name) name ## f
#define NEEDED_ITERS 3

typedef unsigned mantissa;
typedef unsigned int_rep;
typedef unsigned exponent;
typedef unsigned sign;
typedef float type;

#include "../decompose_generic.h"

#ifdef __cplusplus
}
#endif

#endif
