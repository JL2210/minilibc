#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int strncasecmp(const char *str1, const char *str2, size_t len)
{
        int ret;
        char *str1dup = strlwr(strndup(str1, len)),
             *str2dup = strlwr(strndup(str2, len));

        ret = strncmp(str1dup, str2dup, len);

        free(str1dup);
        free(str2dup);
        return ret;
}
