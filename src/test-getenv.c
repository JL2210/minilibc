#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *env;
    if(!argv[1]) return 1;
    env = getenv(argv[1]);
    if(!env) return 1;
    puts(env);
}
