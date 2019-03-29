#include <sys/mman.h>

#include "malloc.h"

void __get_chunk(void)
{
	if (!__mallchunk)
	{
		__mallchunk->ptr = NULL;
		__mallchunk->allocation_ctr = 0;
		__mallchunk->next = NULL;
	}
}
