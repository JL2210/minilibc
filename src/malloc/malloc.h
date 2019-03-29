#ifndef _MALLOC_H
#define _MALLOC_H 1

#include <features.h>

#define CHUNK_SIZE (0x1000000) /* 16MB */

struct malloc_chunk
{
	void *start;
	size_t allocation_ctr;
};

struct allocation_info
{
	size_t size;
	void *start;
	void *end;
};

extern struct __attribute__((__hidden__)) malloc_chunk *__mallchunk;
extern struct __attribute__((__hidden__)) allocation_info *__allocinfo;

extern void __get_chunk(void);
extern void __free_chunk(void);

#endif
