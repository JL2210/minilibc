#include <errno.h>
#include <stddef.h>

#include "libc-deps.h"

const char *__program_invocation_name = NULL, *__program_invocation_short_name = NULL;

weak_alias(__program_invocation_name, program_invocation_name);
weak_alias(__program_invocation_short_name, program_invocation_short_name);
