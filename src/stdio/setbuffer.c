#include <stdio.h>

#include "libc-deps.h"

void __setbuffer(FILE *stream, char *buf, size_t size)
{
    setvbuf(stream, buf, buf ? _IOFBF : _IONBF, size);
}

weak_alias(__setbuffer, setbuffer);
