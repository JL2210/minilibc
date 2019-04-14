#include <stdio.h>

int puts(const char *str)
{
    int len = fputs(str, stderr) + 1;
    putchar('\n');
    return len;
}
