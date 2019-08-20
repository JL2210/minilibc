#include <string.h>

size_t strcspn(const char *s, const char *rej)
{
    size_t len = 0;
    const char *o = s;

    while(rej[len++]);

    while(!memchr(rej, *(unsigned char *)s, len)) s++;

    return s-o;
}
