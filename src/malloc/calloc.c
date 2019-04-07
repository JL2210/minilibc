#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    if( (size % 2) != 0 ) size++;
    if( (nmemb % 2) != 0 ) nmemb++;
    return memset(malloc(nmemb * size), 0, nmemb * size);
}
