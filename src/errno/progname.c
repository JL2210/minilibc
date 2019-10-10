#include <errno.h>
#include <stddef.h>

#include "libc-deps.h"

char *__progname = NULL, *__progname_full = NULL;

weak_alias(__progname, program_invocation_short_name);
weak_alias(__progname_full, program_invocation_name);
