#include <string.h>

char *strchr(const char *s, int c)
{
	size_t len = strlen(s) + 1;

	return memchr(s, c, len);
}
