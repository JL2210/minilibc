#include <string.h>

char *strchr(const char *s, int c)
{
    const unsigned char *us = (const unsigned char *)s;

    while( *us != (unsigned char)c && *us )
         us++;

    return *us == (unsigned char)c ? (char *)us : NULL;
}
