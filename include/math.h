#ifndef _MATH_H
#define _MATH_H 1

#ifdef __GNUC__
# define NAN __builtin_nanf("")
# define INFINITY __builtin_inff()
#else
# define NAN (-(0.f/0.f))
# define INFINITY (1.f/0.f)
#endif

double sqrt(double);
float sqrtf(float);

#endif
