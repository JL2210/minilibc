#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *getenv(const char *name)
{
    char *saveptr;
    char **tmp_env = environ;
    do {
        if(!strcmp(strtok_r(*tmp_env, "=", &saveptr), name))
            return strtok_r(NULL, "=", &saveptr);
    } while(*tmp_env++);
    return NULL;
}
