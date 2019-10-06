#include <string.h>

char *strstr(const char *str1, const char *str2)
{
	return memmem(str1, strlen(str1), str2, strlen(str2));
}
