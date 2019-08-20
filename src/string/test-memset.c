#include <string.h>

int main(void)
{
	int dest[4], *destp;
	destp = memset(dest, 0, sizeof(dest));
	return destp == dest;
}
