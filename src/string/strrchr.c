#include <string.h>

char *strrchr(const char *s, int c)
{
    return (char *)memrchr(s, c, strlen(s) + 1);
}
