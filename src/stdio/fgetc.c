#include <stdio.h>
#include <unistd.h>

int fgetc(FILE *stream)
{
    int ret;
/*  fread(&ret, 1, 1, stream); */
    if(stream->__unget)
    {
        ret = stream->__unget;
        stream->__unget = 0;
    }
    else
    {
        read(fileno(stream), &ret, 1);
        if(ret == EOF) stream->__flags |= __STDIO_EOF;
    }
    return ret;
}
