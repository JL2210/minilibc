#ifndef SYS_STAT_H
#define SYS_STAT_H 1

#include_next <sys/stat.h>

mode_t __umask(mode_t mode);

#endif
