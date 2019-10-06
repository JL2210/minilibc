#!/bin/sh

if [ -z "$1" ]; then
  echo "Insufficient arguments"
  exit 1;
fi


cat << _EOF_
#define _DEFAULT_SOURCE 1
#include <errno.h>
#include <stddef.h>

#include "libc-deps.h"

const char *const __sys_errlist[] = {
_EOF_


awk -v OFS=',' '
    /#define E/ {
        desc = $0
        gsub(/.*\/\*[[:space:]]*|[[:space:]]*\*\//, "\"", desc)
        print "    " desc OFS
    }' $1

cat << _EOF_
    NULL
};

weak_alias(__sys_errlist, sys_errlist);
weak_alias(__sys_errlist, _sys_errlist);
_EOF_
