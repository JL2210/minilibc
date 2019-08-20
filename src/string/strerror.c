#include <errno.h>
#include <string.h>

char *strerror(int err)
{
	char *str;
        if(err > sys_nerr) err = sys_nerr;
        str = (char *)sys_errlist[err];
	return str;
}
