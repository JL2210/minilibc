#include <string.h>

int strncmp(const char *str1, const char *str2, size_t n)
{
	return memcmp(str1, str2, n);
}
