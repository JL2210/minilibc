#include <string.h>
#include <errno.h>
#include <float.h>
#include <math.h>

#ifdef OPT
# define BM 0x5f3759df
#else
# define BM 0x5F375A86
#endif

static const int black_magic = BM;

static inline float rsqrtf(float x)
{
	int i, c;
	float half = x/2.f;
	memcpy(&i, &x, sizeof(i));
	i = black_magic - (i >> 1);
	memcpy(&x, &i, sizeof(x));
	for( c = 0; c < 3; c++ )
		x *= 1.5f - half*x*x;
	return x;
}

float sqrtf(float x)
{
	if(x < -0.f)
	{
		errno = EDOM;
		return -NAN;
	}
	if(x == 0.f || x != x || x > FLT_MAX)
	{
		return x;
	}
	return 1.f/rsqrtf(x);
}

int main(void)
{
	printf("%.32f\n", sqrtf(93.f));
}
