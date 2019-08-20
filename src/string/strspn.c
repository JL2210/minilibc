#include <string.h>

size_t strspn(const char *s, const char *acc)
{
    size_t len = 0;
    const char *o = s;

    while(acc[len]) len++;

    while(memchr(acc, *(unsigned char *)s, len)) s++;

    return s-o;
}
