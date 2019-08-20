#include <string.h>

char *strchrnul(const char *s, int c)
{
    const unsigned char *us = (const unsigned char *)s;
    while( *us && *us != (unsigned char)c) us++;
    return (char *)us;
}
