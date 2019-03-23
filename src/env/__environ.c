#include <unistd.h>
#include <stddef.h>
#include "weak.h"

char **__environ = NULL;
weak_alias(environ, __environ);
