#include <string.h>
#include <stdlib.h>

char *strdup(const char *str)
{
        const char *s = str;
        char *dest, *d;

	while(*str++);
	d = dest = malloc(str - s);
	if(dest) while((*d++ = *s++));

        return dest;
}
