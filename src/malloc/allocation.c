#include <unistd.h>
#include <sys/mman.h>

#include "malloc.h"

void __get_next_allocation(size_t size)
{
	size_t ctr = 0;
	int found_allocation = 0;
	struct allocation_info *tmp_alloc = __allocinfo;

	if (!__allocinfo)
	{
		__allocinfo = __mallchunk->start;
		__allocinfo->start = __mallchunk->start;
		__allocinfo->size = 0;
		__allocinfo->free = 0;
		__allocinfo->next = NULL;
		__allocinfo->prev = NULL;
	}
	else
	{
		for( ctr = 0; ctr < __mallchunk->alloc_cnt; ctr++,
					tmp_alloc = tmp_alloc->next )
		{
			if( tmp_alloc->free &&
				tmp_alloc->size >= size )
			{
				found_allocation = 1;
				tmp_alloc->prev->next = tmp_alloc->next;
				tmp_alloc->next->prev = tmp_alloc->prev;
				tmp_alloc->next = NULL;
			}
		}
		if(!found_allocation &&
			(__allocinfo->start - __mallchunk->start)
					> CHUNK_SIZE)
		{
			__get_next_chunk();
			tmp_alloc = __allocinfo->start
					+ __allocinfo->size;
		}
	}
	__allocinfo->next = tmp_alloc;
	__allocinfo->next->prev = __allocinfo;
	__allocinfo = __allocinfo->next;
	__allocinfo->size = size;
	__allocinfo->free = 0;
}
