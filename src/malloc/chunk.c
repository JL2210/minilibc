#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "malloc.h"

void __get_next_chunk(void)
{
	struct malloc_chunk *mallchunk = sbrk(sizeof(*mallchunk));

	if (!__mallchunk)
	{
		__mallchunk = mallchunk;
		__mallchunk->chunk_cnt = 0;
		__mallchunk->alloc_cnt = 0;
		__mallchunk->prev = NULL;
		__mallchunk->next = NULL;
	}
	else
	{
		__mallchunk->chunk_cnt++;
		__mallchunk->next = mallchunk;
		__mallchunk->next->chunk_cnt =
			__mallchunk->chunk_cnt;
		__mallchunk->next->prev = __mallchunk;
		__mallchunk = __mallchunk->next;
	}

	__mallchunk->start = mmap(NULL,
			    CHUNK_SIZE,
		PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANON,
				    -1,
				    0);
}
