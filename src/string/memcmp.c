#include <string.h>

int memcmp(const void *ptr1, const void *ptr2, size_t n)
{
    const unsigned char *s1 = ptr1, *s2 = ptr2;

    if(ptr1 == ptr2)
        return 0;

    while( n && *s1 == *s2 )
    {
        s1++;
        s2++;
        n--;
    }

equal:
    return *s1 - *s2;
}
