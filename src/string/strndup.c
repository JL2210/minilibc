#include <string.h>
#include <stdlib.h>

char *strndup(const char *s, size_t len)
{
    size_t num = strnlen(s, len);
    char *d = calloc(1, num+1);
    if(d)
    {
        memcpy(d, s, num);
        d[num] = 0;
    }
    return d;
}
