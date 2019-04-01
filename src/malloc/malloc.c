#include <stdlib.h>
#include <unistd.h>

#include "malloc.h"

void *malloc(size_t size)
{
	if(!size)
		return sbrk(0);

	if(!__mallchunk)
		__get_next_chunk();

	__get_next_allocation(size);
	return __allocinfo->start;
}
