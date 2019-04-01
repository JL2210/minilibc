#ifndef _MALLOC_H
#define _MALLOC_H 1

#include <features.h>
#include <sys/types.h>

#ifdef __PTR16__
# define CHUNK_SIZE (0x4000) /* 16K */
#else
# define CHUNK_SIZE (0x10000) /* 64K */
#endif

struct malloc_chunk
{
	void *start;
	size_t alloc_cnt;
	size_t chunk_cnt;
	struct malloc_chunk *prev;
	struct malloc_chunk *next;
};

struct allocation_info
{
	void *start;
	size_t size;
	int free;
	struct allocation_info *prev;
	struct allocation_info *next;
};

extern struct malloc_chunk *__mallchunk;
extern struct allocation_info *__allocinfo;

extern void __get_next_chunk(void);
extern void __get_next_allocation(size_t size);

#endif
