#include <string.h>

void *memset(void *ptr, int value, size_t num)
{
	size_t ctr;

	for( ctr = 0; ctr < num; ctr++ )
		((char *)ptr)[ctr] = value;

	return ptr;
}
