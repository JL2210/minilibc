#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long labs(long a)
{
    if(a == LONG_MIN)
    {
        fputs("Result of labs() cannot be represented!\n", stderr);
        abort();
    }

    return a < 0 ? -a : a;
}
