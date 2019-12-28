#include <stdlib.h>
#include <stdint.h>

#define SEED __extension__ 0x8F1334AA159590A4ULL

static uint64_t seed;

void srand(unsigned s)
{
    seed = --s;
}

int rand(void)
{
    seed = SEED * (seed + 1);
    return seed >> 33;
}
