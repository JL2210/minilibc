#include <string.h>

size_t strspn(const char *s, const char *acc)
{
    size_t len = strlen(acc);
    const char *o = s;

    while(memchr(acc, *(const unsigned char *)s, len)) s++;

    return s-o;
}
