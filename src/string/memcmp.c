#include <string.h>

#define ucp(x) ((unsigned char *)(x))

int memcmp(const void *ptr1, const void *ptr2, size_t n)
{
    size_t ctr;

    for( ctr = 0; ctr < n; ctr++ )
    {
        if(ucp(ptr1)[ctr] > ucp(ptr2)[ctr]) goto not_equal;
        else if(ucp(ptr2)[ctr] > ucp(ptr1)[ctr]) goto not_equal;
    }
    return 0;
not_equal:
    return ucp(ptr1)[ctr] - ucp(ptr2)[ctr];
}
