#include <stddef.h>

void *
#ifdef _BUILD_CALLOC
calloc
#elif defined(_BUILD_MALLOC)
malloc
#else
#error Must define _BUILD_MALLOC or _BUILD_MALLOC
#endif
(
#ifdef _BUILD_CALLOC
size_t nmemb,
#endif
size_t size
)
{
#ifdef _BUILD_CALLOC
	(void)nmemb;
#endif
	(void)size;
	return NULL;
}
