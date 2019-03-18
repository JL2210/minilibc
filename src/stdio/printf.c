#include <stdio.h>
#include <stdarg.h>

int printf(char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	return EOF;
}
