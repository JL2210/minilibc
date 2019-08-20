#!/bin/sh

if [ -z "$1" ]; then
  echo "Insufficient arguments"
  exit 1;
fi


cat << _EOF_
#include <errno.h>
#include <stddef.h>

const char *const sys_errlist[] = {
_EOF_

awk -v OFS=',' '
    /#define E/ {
        desc = $0
        gsub(/.*\/\*[[:space:]]*|[[:space:]]*\*\//, "\"", desc)
        print "    " desc OFS
    }' $1

cat << _EOF_
    "unknown error code",
    NULL
};
_EOF_
