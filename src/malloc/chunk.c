#include <unistd.h>
#include <sys/mman.h>

#include "malloc.h"

void __get_next_chunk(void)
{
	if (!__mallchunk)
	{
		__mallchunk = mmap(	   sbrk(0),
			      sizeof(*__mallchunk),
		PROT_READ | PROT_WRITE | PROT_EXEC,
		MAP_PRIVATE | MAP_FIXED | MAP_ANON,
						-1,
						0);
		sbrk(sizeof(*__mallchunk));

		__mallchunk->start = mmap( sbrk(0),
					CHUNK_SIZE,
		PROT_READ | PROT_WRITE | PROT_EXEC,
		MAP_PRIVATE | MAP_FIXED | MAP_ANON,
						-1,
						0);
		sbrk(CHUNK_SIZE);

		__mallchunk->chunk_cnt = 0;
		__mallchunk->alloc_cnt = 0;
		__mallchunk->prev = NULL;
		__mallchunk->next = NULL;
	}
	else
	{
		__mallchunk->chunk_cnt++;
		__mallchunk->next = mmap(  sbrk(0),
			sizeof(*__mallchunk->next),
		PROT_READ | PROT_WRITE | PROT_EXEC,
		MAP_PRIVATE | MAP_FIXED | MAP_ANON,
						-1,
						0);
		sbrk(sizeof(*__mallchunk->next));
		__mallchunk->next->chunk_cnt =
			__mallchunk->chunk_cnt;
		__mallchunk->next->prev = __mallchunk;
		__mallchunk = __mallchunk->next;
		__mallchunk->start = mmap( sbrk(0),
					CHUNK_SIZE,
		PROT_READ | PROT_WRITE | PROT_EXEC,
		MAP_PRIVATE | MAP_FIXED | MAP_ANON,
						-1,
						0);
		sbrk(CHUNK_SIZE);
	}
}
