#include <errno.h>
#include <stdio.h>
#include <string.h>

char *strerror(int err)
{
    if((unsigned)(err - 1) >= (unsigned)__sys_nerr)
        return (char *)"unknown error code";

    return (char *)__sys_errlist[err - 1];
}
