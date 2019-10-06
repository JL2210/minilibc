#ifndef FCNTL_H
#define FCNTL_H 1

#include_next <fcntl.h>

int __open(const char *, int, ...);
int __openat(int, const char *, int, ...);

#endif
