#include <string.h>

char *strncpy(char *dest, char *src, size_t len)
{
	size_t ctr;

	for( ctr = 0; ctr < len; ctr++ )
		dest[ctr] = src[ctr];

	return dest;
}
