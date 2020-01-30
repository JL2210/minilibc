#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int abs(int a)
{
    if(a == INT_MIN)
    {
        fputs("Result of abs() cannot be represented!\n", stderr);
        abort();
    }

    return a < 0 ? -a : a;
}
