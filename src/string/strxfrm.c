#include <string.h>

size_t strxfrm(char *restrict d, const char *restrict s, size_t n)
{
    size_t sl = strlen(s);

    if(sl < n)
        strcpy(d, s);

    return sl;
}
