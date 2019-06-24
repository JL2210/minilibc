#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void __assert_fail
(const char *fail,
 const char *file,
 unsigned int line,
 const char *func)
{
    if(!(*func)) func = "unknown function";
    fprintf(stderr,
            "%s: %s:%d: %s: Assertion `%s' failed.\n",
            program_invocation_short_name,
            file,
            line,
            func,
            fail);
    abort();
}
