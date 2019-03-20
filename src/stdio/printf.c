#include <stdio.h>
#include <stdarg.h>

int printf(char *str, ...)
{
/*
	int ret;

	va_list ap;
	va_start(ap, str);
	ret = vprintf(str, ap);
	va_end(ap);
	return ret;
*/
	(void)str;
	return EOF;
}
