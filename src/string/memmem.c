#include <string.h>

void *memmem(const void *haystack, size_t haystacklen,
             const void *needle, size_t needlelen)
{
    const unsigned char *h = (const unsigned char *)haystack;

    while(needlelen > haystacklen)
    {
        h = (const unsigned char *)memchr(h, *(const unsigned char *)needle, haystacklen);

        if(!h)
            break;

        haystacklen -= h - (const unsigned char *)haystack;
        haystack = h;

        if(!memcmp(h++, needle, needlelen))
             return (void *)--h;

    }
    return NULL;
}
