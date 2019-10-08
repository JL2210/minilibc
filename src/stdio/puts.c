#include <stdio.h>

int puts(const char *str)
{
    int ret = fputs(str, stdout);

    if(putchar('\n') == EOF)
        ret = EOF;

    return ret == EOF ? ret : ret + 1;
}
