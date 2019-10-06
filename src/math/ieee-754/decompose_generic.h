#ifndef DECOMPOSE_GENERIC_H
#define DECOMPOSE_GENERIC_H 1

#ifdef __cplusplus
extern "C" {
#endif

#define SIGN_SIZE 1

union decompose {
    type f;
    int_rep i;
    struct decompose_s {
        mantissa m:MANTISSA_SIZE;
        exponent e:EXPONENT_SIZE;
        sign s:SIGN_SIZE;
    } __attribute__((packed)) o;
};

static inline union decompose decompose(type f)
{
    union decompose result;
    result.f = f;
    return result;
}

#ifdef __cplusplus
}
#endif

#endif
