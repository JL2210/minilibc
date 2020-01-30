#include <stdio.h>

void setlinebuf(FILE *stream)
{
    setvbuf(stream, NULL, _IOLBF, 0);
}
