#include <unistd.h>
#include <stddef.h>

#include "libc-deps.h"

char **__environ = NULL;

weak_alias(__environ, _environ);
weak_alias(__environ, environ);
