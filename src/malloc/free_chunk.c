#include <sys/mman.h>

#include "malloc.h"

void __free_chunk(void)
{
	size_t ctr;

	for( ctr = 0; ctr < __mallchunk->allocation_ctr; ctr++ )
	{
		__allocinfo[ctr].start = NULL;
		__allocinfo[ctr].end = NULL;
	}

	__mallchunk->ptr = NULL;
	__mallchunk->allocation_ctr = 0;
}
