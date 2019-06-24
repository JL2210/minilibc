#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>

#include "malloc.h"

int __get_next_chunk(size_t size)
{
    mchunk *mallchunk = (mchunk *)
                        mmap(NULL,
                             size,
           PROT_READ | PROT_WRITE,
       MAP_SHARED | MAP_ANONYMOUS,
                               -1,
                               0);
    if(mallchunk == MAP_FAILED)
    {
        errno = ENOMEM;
        return -1;
    }

    memset(mallchunk, 0, sizeof(*mallchunk));

    if (!__malloc_chunk)
    {
        __malloc_chunk = mallchunk;
        __malloc_chunk->prev = NULL;
    }
    else
    {
        __malloc_chunk->next = mallchunk;
        __malloc_chunk->next->prev = __malloc_chunk;
        __malloc_chunk = __malloc_chunk->next;
    }

    __malloc_chunk->next = NULL;
    __malloc_chunk->alloc_cnt = 0;

    __malloc_chunk->start = __malloc_chunk + 1;
    return 0;
}
