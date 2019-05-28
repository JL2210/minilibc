#include <stdio.h>
#include <stddef.h>

/* Simple env program */

int main(int argc, char **argv, char **envp)
{
    int a = 0;

    (void)argc;
    (void)argv;

    for( a = 0; envp[a]; a++ )
        puts(envp[a]);

    return 0;
}
