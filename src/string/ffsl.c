#include <strings.h>
#include <limits.h>

int ffsl(long i)
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
