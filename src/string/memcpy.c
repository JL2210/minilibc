#include <string.h>

void *memcpy(void *dest, const void *src, size_t num)
{
	size_t ctr;

	for( ctr = 0; ctr < num; ctr++ )
		((char *)dest)[ctr] = ((char *)src)[ctr];

	return dest;
}
