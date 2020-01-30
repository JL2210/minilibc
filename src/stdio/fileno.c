#include <stdio.h>
#include <errno.h>

#include "libc-deps.h"

int __fileno(FILE *fp)
{
    int ret = fp->fileno;

    /* XXX: Is this needed? */
    if(ret < 0)
    {
        ret = -1;
        errno = EBADF;
    }

    return ret;
}

weak_alias(__fileno, fileno);
