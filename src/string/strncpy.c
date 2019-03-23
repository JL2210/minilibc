#include <string.h>

char *strncpy(char *dest, char *src, size_t len)
{
	size_t ctr = 0;

	while(ctr < len)
	{
		dest[ctr] = src[ctr];
		ctr++;
	}

	return dest;
}
