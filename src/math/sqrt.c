#include <string.h>
#include <errno.h>
#include <float.h>
#include <math.h>

static const long long black_magic = 0x5FE6EB50C7B537A9;

static inline double rsqrt(double x)
{
	long long i, c;
	double half = x/2.;
	memcpy(&i, &x, sizeof(i));
	i = black_magic - (i >> 1);
	memcpy(&x, &i, sizeof(x));
	for( c = 0; c < 4; c++ )
		x *= 1.5 - half*x*x;
	return x;
}

double sqrt(double x)
{
	if(x < -0.)
	{
		errno = EDOM;
		return -NAN;
	}
	if(x == 0. || x != x || x > DBL_MAX)
	{
		return x;
	}
	return 1.f/rsqrt(x);
}
