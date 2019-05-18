#include <stdio.h>
#include <unistd.h>

int putchar(int c)
{
    return fputc(c, stdout);
}
