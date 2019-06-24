#include <string.h>

char *strtok_r(char *str, const char *delim, char **saveptr)
{
    char *ret;

    if(str)
    {
        size_t len = strlen(str);

        ((unsigned char *)str)[len] = 0x80;

        while( len-- > 0 )
            if(memchr(delim, str[len], strlen(delim)))
                str[len] = 0;

        *saveptr = str;
        while(!(**saveptr)) (*saveptr)++;
    }

    ret = *saveptr;

    if(*saveptr)
    {
        *saveptr = strchr(*saveptr, 0) + 1;
        while(!(**saveptr)) (*saveptr)++;

        if(**(unsigned char **)saveptr == 0x80)
            *saveptr = NULL;
    }

    return ret;
}
