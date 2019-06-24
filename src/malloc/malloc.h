#ifndef _MALLOC_H
#define _MALLOC_H 1

#include <features.h>
#include <stdint.h>
#include <stddef.h>

#define CHUNK_SIZE (0x4000)

struct malloc_chunk
{
    void *start;
    size_t alloc_cnt;
    struct malloc_chunk *prev;
    struct malloc_chunk *next;
};

struct allocation_info
{
    void *start;
    size_t size;
    struct allocation_info *prev;
    struct allocation_info *next;
    intptr_t free;
};

typedef struct malloc_chunk mchunk;
typedef struct allocation_info ainfo;

extern mchunk *__malloc_chunk;
extern ainfo *__allocation_info;

extern int __get_next_chunk(size_t size);
extern int __get_next_allocation(size_t size);

#endif
