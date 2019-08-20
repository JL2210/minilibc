#ifndef _FLOAT_PARTS_H
#define _FLOAT_PARTS_H 1

#include <features.h>
#include <stdbool.h>
#include <stdint.h>

typedef union float_parts
{
    struct {
        bool sign:1;
        uint8_t exponent:8;
        uint32_t mantissa:23;
    } representation;
    int ivalue;
    float value;
} float_parts_t;

typedef union double_parts
{
    struct {
        bool sign:1;
        uint16_t exponent:11;
        uint64_t mantissa:52;
    } representation;
    long long ivalue;
    double value;
} double_parts_t;

#endif
