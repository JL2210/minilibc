#include <string.h>

char *strchr(const char *s, int c)
{
    return (char *)memchr(s, c, strlen(s) + 1);
}
