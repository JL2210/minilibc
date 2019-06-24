#!/bin/sh

if [ -z "$1" ]; then
  echo "Insufficient arguments"
  exit 1;
fi


cat << _EOF_
#include <errno.h>

static struct strerror {
	int num;
	const char *name;
	const char *description;
} strerrors[] = {
_EOF_

awk -v OFS=',' '
    /#define E/ {
        desc = $0
        gsub(/.*\/\*[[:space:]]*|[[:space:]]*\*\//, "\"", desc)
        print "\t{ " $2, " \"" $2 "\"", " " desc " }" OFS
    }' $1

cat << _EOF_
	{ 0, 0, 0 }
};
_EOF_
