#include <string.h>

size_t strcspn(const char *s, const char *rej)
{
    size_t len = strlen(rej)+1;
    const char *o = s;

    while(!memchr(rej, *(unsigned char *)s, len)) s++;

    return (size_t)(s-o);
}
