#include <stdlib.h>
#include <stdint.h>

static unsigned seed = 1;

int rand_r(unsigned *seedp)
{
    unsigned ret;
    uintptr_t reg = *(uintptr_t *)"Minilibc";
    if(*seedp*2 <= (unsigned)RAND_MAX) *seedp = (*seedp + 1) * (reg + 1);
    *seedp = *seedp * reg + 1;
    ret = *seedp % ((unsigned)RAND_MAX+1);
    return ret;
}

int rand(void)
{
	return rand_r(&seed);
}

void srand(unsigned s)
{
    seed = s;
}
