#include <string.h>

size_t strlen(char *str)
{
	size_t ctr = 0;

	while(str[ctr]) ctr++;

	return ctr;
}
