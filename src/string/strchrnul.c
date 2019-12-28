#include <string.h>

char *strchrnul(const char *s, int c)
{
    const unsigned char *us = s;

    while( *us != (unsigned char)c && *us )
         us++;

    return (char *)us;
}
