#include <stdio.h>
#include <string.h>

int puts(char *str)
{
	size_t len = strlen(str);
	write(1, str, len);
	putchar('\n');
	return len + 1;
}
