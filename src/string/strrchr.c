#include <string.h>

char *strrchr(const char *s, int c)
{
    size_t len;
    const unsigned char *us = (const unsigned char *)s;

    while(*us) us++;
    len = --us - (const unsigned char *)s;

    while(len--)
    {
        if(*us == (unsigned char)c)
            return (char *)us;
        us--;
    }

    return NULL;
}
