#include <stdio.h>
#include <string.h>
#include <unistd.h>

int puts(const char *str)
{
	size_t len = strlen(str);
	write(1, str, len);
	putchar('\n');
	return len + 1;
}
