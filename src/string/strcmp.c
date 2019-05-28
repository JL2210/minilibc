#include <string.h>

#define GREATER(x,y) ((x) > (y) ? (x) : (y))

int strcmp(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1),
           len2 = strlen(str2);
    return strncmp(str1, str2, GREATER(len1, len2));
}
