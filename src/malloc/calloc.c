#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void *calloc(size_t nmemb, size_t size)
{
    size_t total_size;
    void *ret;

    total_size = size * nmemb;

    if(size != 0 && (total_size / size) != nmemb)
    {
        errno = ENOMEM;
        return NULL;
    }
    ret = malloc(total_size);

    if(!ret) return NULL;
    return memset(ret, 0, total_size);
}
