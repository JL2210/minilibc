#include <stdio.h>

int vprintf(char *fmt, va_list ap)
{
	return vfprintf(stdin, fmt, ap);
}
