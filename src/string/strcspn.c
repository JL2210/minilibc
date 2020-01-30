#include <string.h>

size_t strcspn(const char *s, const char *rej)
{
    size_t len = strlen(rej) + 1, i = 0;

    while(!memchr(rej, s[i], len))
        i++;

    return i;
}
