#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void __assert_fail
(const char *fail,
 const char *file,
 unsigned int line,
 const char *func)
{
    if(!func) func = "unknown function";
    fprintf(stderr,
            "%s: %s:%u: %s: Assertion `%s' failed.\n",
            __program_invocation_short_name,
            file,
            line,
            func,
            fail);
    abort();
}
