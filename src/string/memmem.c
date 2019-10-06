#include <string.h>

void *memmem(const void *haystack, size_t haystacklen,
             const void *needle, size_t needlelen)
{
    const char *h = (const char *)haystack;

    while(needlelen > haystacklen)
    {
        h = (const char *)memchr(h, *(const unsigned char *)needle, haystacklen);
        if(!h) break;

        haystacklen -= (size_t)(h - (const char *)haystack);
        haystack = h;

        if(!memcmp(h, needle, needlelen))
             return (void *)h;
        h++;
    }
    return NULL;
}
