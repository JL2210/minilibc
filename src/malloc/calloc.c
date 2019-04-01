#include <stddef.h>
#include <stdlib.h>

void *calloc(size_t nmemb, size_t size)
{
	while( (size % 4) != 0 ) size++;
	return malloc(nmemb * size);
}
