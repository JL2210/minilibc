#include <stdlib.h>
#include <limits.h>

long labs(long a)
{
	return a < 0 ? -a : a;
}
