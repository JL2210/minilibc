#ifndef _FCNTL_H
# error "Never include <bits/fcntl.h> directly; use <fcntl.h> instead."
#endif

#define AT_FDCWD    -100

#define O_RDONLY    0000000
#define O_WRONLY    0000001
#define O_RDWR      0000002
#define O_CREAT     0000100
#define O_EXCL      0000200
#define O_TRUNC     0001000
#define O_APPEND    0002000
#define O_LARGEFILE 0100000
