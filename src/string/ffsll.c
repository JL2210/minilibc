#include <strings.h>
#include <limits.h>

#include "libc-deps.h"

int __ffsll(long long i)
{
    int l = sizeof(i)*CHAR_BIT, ctr = 0;

    while( l-- )
    {
        if(i & (1u << ctr))
            return ++ctr;
        ctr++;
    }

    return 0;
}

weak_alias(__ffsll, ffsll);
