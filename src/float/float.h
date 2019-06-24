#ifndef _FLOAT_H
#define _FLOAT_H 1

#include <features.h>
#include <stdbool.h>

typedef struct float_parts
{
    bool sign:1;
    uint8_t exponent:8;
    uint32_t mantissa:23;
} float_parts_t;

typedef union float_parts_union
{
    float val;
    float_parts_t parts;
} float_parts_union_t;

typedef struct double_parts
{
    bool sign:1;
    uint16_t exponent:11;
    uint64_t mantissa:52;
} double_parts_t;

typedef union double_parts_union
{
    double val;
    double_parts_t parts;
} double_parts_union_t;

#endif
