#include <stdio.h>

void setbuffer(FILE *stream, char *buf, size_t size)
{
    setvbuf(stream, buf, buf ? _IOFBF : _IONBF, size);
}
