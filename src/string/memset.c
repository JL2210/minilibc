#include <string.h>

void *memset(void *ptr, int value, size_t num)
{
	size_t ctr = 0;

	while(ctr < num)
	{
		((char *)ptr)[ctr] = value;
		ctr++;
	}

	return ptr;
}
