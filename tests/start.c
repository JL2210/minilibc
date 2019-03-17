#include <stdio.h>

/* Test of argc, argv, envp, stdio, and return codes */

int puts(char *str) { if (str && *str) return 1; else return 0; }

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
