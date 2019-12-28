#include <string.h>

void *__rawmemchr(const void *p, int b)
{
    const unsigned char *m = p;

    while(*m != (unsigned char)b)
        m++;

    return (void *)m;
}

weak_alias(__rawmemchr, rawmemchr);
