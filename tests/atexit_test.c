#include <stdlib.h>
#include <stdio.h>

void atexit_test(void)
{
	puts("atexit() test...");
}

int main()
{
	atexit(atexit_test);
	return 0;
}
