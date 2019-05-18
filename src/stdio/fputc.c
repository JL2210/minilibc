#include <stdio.h>
#include <unistd.h>

int fputc(int c, FILE *stream)
{
        write(fileno(stream), &c, 1);
        return c;
}
