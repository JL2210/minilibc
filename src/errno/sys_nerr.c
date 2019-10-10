#include <errno.h>

#include "libc-deps.h"

int __sys_nerr = EBADSLT;

weak_alias(__sys_nerr, _sys_nerr);
weak_alias(__sys_nerr, sys_nerr);
