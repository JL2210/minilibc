#include <string.h>

char *strcpy(char *dest, const char *src)
{
	size_t len = strlen(src) + 1;
	return strncpy(dest, src, len);
}
