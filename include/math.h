#ifndef _MATH_H
#define _MATH_H 1

#include <features.h>

#define __need_float_t
#define __need_double_t

#include <bits/defs.h>

#ifdef __GNUC__
# define NAN __builtin_nanf("")
# define INFINITY __builtin_inff()
# define HUGE_VALF __builtin_huge_valf()
# define HUGE_VAL __builtin_huge_val()
# define HUGE_VALL __builtin_huge_vall()
#else
# define NAN (-(0.f/0.f))
# define INFINITY (1.f/0.f)
# define HUGE_VALF (1.f/0.f)
# define HUGE_VAL (1.0/0.0)
# define HUGE_VALL (1.l/0.l)
#endif

#define M_PI (3.14159265358979323846264338327950288)
#define M_PI_2 (M_PI/2.0)

#define isnan(x) ((x) != (x))

__BEGIN_DECLS

long double fabsl(long double);
double fabs(double);
float fabsf(float);

long double fmodl(long double, long double);
double fmod(double, double);
float fmodf(float, float);

long double nanl(const char *);
double nan(const char *);
float nanf(const char *);

long double sqrtl(long double);
double sqrt(double);
float sqrtf(float);

__END_DECLS

#endif
