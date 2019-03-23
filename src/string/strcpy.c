#include <string.h>

char *strcpy(char *dest, char *src)
{
	size_t len = strlen(src) + 1;
	return strncpy(dest, src, len);
}
