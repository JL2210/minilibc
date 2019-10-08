#ifndef FCNTL_H
#define FCNTL_H 1

#include "../../include/fcntl.h"

extern int __open(const char *, int, ...);
extern int __openat(int, const char *, int, ...);

#endif
