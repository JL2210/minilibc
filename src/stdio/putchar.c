#include <stdio.h>
#include <string.h>

int putchar(int c)
{
	c = (int)write(1, (char *)&c, 1);
	return c;
}
