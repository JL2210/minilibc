#include <string.h>

int strncmp(const char *ptr1, const char *ptr2, size_t n)
{
    while( n-- > 0 && *ptr1 && *ptr2 )
        if(*ptr1++ != *ptr2++)
            goto not_equal;

    return 0;
not_equal:
    return *--ptr1 - *--ptr2;
}
