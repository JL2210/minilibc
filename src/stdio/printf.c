#include <stdio.h>

int printf(char *fmt, ...)
{
	int ret;

	va_list ap;
	va_start(ap, fmt);
	ret = vprintf(fmt, ap);
	va_end(ap);
	return ret;
}
