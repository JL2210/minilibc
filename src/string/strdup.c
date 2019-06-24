#include <string.h>
#include <stdlib.h>

char *strdup(const char *str)
{
        char *ret = (char *)malloc(strlen(str)+1);
        return strcpy(ret, str);
}
