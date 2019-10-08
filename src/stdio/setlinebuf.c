#include <stdio.h>

#include "libc-deps.h"

void __setlinebuf(FILE *stream)
{
    setvbuf(stream, NULL, _IOLBF, 0);
}

weak_alias(__setlinebuf, setlinebuf);
