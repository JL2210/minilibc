#include <string.h>

int strncmp(const char *str1, const char *str2, size_t n)
{
    size_t ctr;

    for( ctr = 0; ctr < n; ctr++ )
    {
        if(str1[ctr] > str2[ctr]) return 1;
        else if(str2[ctr] > str1[ctr]) return -1;
    }
    return 0;
}
