#include <stdio.h>

int puts(char *string)
#if 0
{
	if(*string)
		return 0;
	else
		return 1;
	return 1;
}
#else
;
#endif

int printf(char *string, ...)
#if 0
{
	puts(string);
}
#else
;
#endif

int main(int argc, char **argv, char **envp)
{
	int a = 0;

	printf("%d\n", argc);
	for( a = 0; a < argc; a++ )
		puts(argv[a]);
	for( a = 0; envp != NULL && envp[a] != NULL; a++ )
		puts(envp[a]);
	return 16;
}
