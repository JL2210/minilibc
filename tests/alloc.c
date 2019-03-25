#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	size_t *len = NULL;
	int ctr = 0;
	char **buf = NULL;
	len = (size_t *)sbrk(sizeof(size_t)*argc);
	memset(len, 0, sizeof(size_t)*argc);
	buf = (char **)sbrk(sizeof(char *)*argc);
	memset(buf, 0, sizeof(char *)*argc);
	while( ctr < argc )
	{
		len[ctr] = strlen(argv[ctr]) + 1;
		buf[ctr] = (char *)sbrk(len[ctr]);
		memset(buf[ctr], 0, len[ctr]);
		strncpy(buf[ctr], argv[ctr], len[ctr]);
		puts(buf[ctr]);
		sbrk(-len[ctr]);
		ctr++;
	}
	sbrk(-(sizeof(char *)*argc));
	sbrk(-(sizeof(size_t)*argc));
	return 0;
}
