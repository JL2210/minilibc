#include <string.h>

#define LESSER(x,y) (x > y ? y : x)
#define GREATER(x,y) (x > y ? x : y)

int strcmp(const char *str1, const char *str2)
{
    int ret;
    size_t len,
           len1 = strlen(str1),
           len2 = strlen(str2);
    len = LESSER(len1, len2);
    ret = strncmp(str1, str2, len);
    if(ret == 0 && len1 != len2)
    {
        return 0; /* FIXME */
    }
    return len;
}
