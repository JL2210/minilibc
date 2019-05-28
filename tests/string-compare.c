#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int ret = 1;
	if(argc < 3)
	{
		puts("Insufficient arguments.");
		goto ret;
	}
	if((ret = strcmp(argv[1], argv[2])))
	{
		printf("Strings argv[1] (\"%s\") and argv[2] (\"%s\") are not equal.\n",
			argv[1], argv[2]);
		goto ret;
	}
	printf("Strings argv[1] (\"%s\") and argv[2] (\"%s\") are equal.\n",
		argv[1], argv[2]);
	return 0;
ret:	return ret;
}
