#include <stdio.h>
#include <string.h>

int puts(char *str)
{
	int len = strlen(str);
	write(1, str, len);
	putchar('\n');
	return len + 1;
}
