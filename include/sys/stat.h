#ifndef _SYS_STAT_H
#define _SYS_STAT_H 1

#include <features.h>

#define __need_dev_t
#define __need_ino_t
#define __need_uid_t
#define __need_gid_t
#define __need_off_t
#define __need_mode_t
#define __need_time_t
#define __need_nlink_t
#define __need_blkcnt_t
#define __need_blksize_t

#include <bits/defs.h>

__BEGIN_DECLS

#define S_IFMT   0170000 /* These bits determine file type. */
#define S_IFDIR  0040000 /* Directory. */
#define S_IFCHR  0020000 /* Character device. */
#define S_IFBLK  0060000 /* Block device. */
#define S_IFREG  0100000 /* Regular file. */
#define S_IFIFO  0010000 /* FIFO. */
#define S_IFLNK  0120000 /* Symbolic link. */
#define S_IFSOCK 0140000 /* Socket. */
#define S_ISUID  0004000 /* Set user ID on execution. */
#define S_ISGID  0002000 /* Set group ID on execution. */
#define S_ISVTX  0001000 /* Save swapped text after use (sticky). */
#define S_IREAD  0000400 /* Read by owner. */
#define S_IWRITE 0000200 /* Write by owner. */
#define S_IEXEC  0000100 /* Execute by owner. */

mode_t umask(mode_t);
#ifdef _GNU_SOURCE
mode_t getumask(void);
#endif

__END_DECLS

#endif
