#include <errno.h>
#include <stdio.h>
#include <string.h>

char *strerror(int err)
{
	char *str;
        if((unsigned)(err-1) >= (unsigned)__sys_nerr) return (char *)"unknown error code";
        str = (char *)__sys_errlist[err-1];
	return str;
}
