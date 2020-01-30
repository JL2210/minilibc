#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long llabs(long long a)
{
    if(a == LLONG_MIN)
    {
        fputs("Result of llabs() cannot be represented!\n", stderr);
        abort();
    }

    return a < 0 ? -a : a;
}
