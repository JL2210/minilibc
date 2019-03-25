#include <string.h>

char *strncpy(char *dest, char *src, size_t len)
{
	size_t ctr;

	for( ctr = 0; ctr < len && src[ctr] != '\0'; ctr++ )
		dest[ctr] = src[ctr];
	while( ctr < len )
	{
		dest[ctr] = '\0'; ctr++;
	}

	return dest;
}
