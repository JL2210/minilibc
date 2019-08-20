#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

size_t fwrite(const void *p, size_t size, size_t count, FILE *stream)
{
    size_t ctr = 0;
    while( ctr < count )
    {
        if(write(fileno(stream), p, size) == -1)
            break;
        p = (const char *)p + size;
        ctr++;
    }
    return ctr;
}
