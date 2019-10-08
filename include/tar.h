#ifndef _TAR_H
#define _TAR_H 1

#include <features.h>

/* General definitions */
 /* Used in the magic field in the ustar header block,
  * including the trailing null byte
  */
#define TMAGIC   "ustar"
 /* Length in octets of the magic field */
#define TMAGLEN  6
 /* Used in the version field in the ustar header block,
  * excluding the trailing null byte
  */
#define TVERSION "00"
 /* Length in octets of the version field */
#define TVERSLEN 2

/* Typeflag field definitions */
#define AREGTYPE '\0' /* Regular file */
#define REGTYPE  '0' /* Regular file */
#define LNKTYPE  '1' /* Link */
#define SYMTYPE  '2' /* Symbolic link */
#define CHRTYPE  '3' /* Character special */
#define BLKTYPE  '4' /* Block special */
#define DIRTYPE  '5' /* Directory */
#define FIFOTYPE '6' /* FIFO special */
#define CONTTYPE '7' /* Reserved */

/* Mode field bit definitions (octal) */
#define TOEXEC  00001 /* Execute/search by other */
#define TOWRITE 00002 /* Write by other */
#define TOREAD  00004 /* Read by other */
#define TGEXEC  00010 /* Execute/search by group */
#define TGWRITE 00020 /* Write by group */
#define TGREAD  00040 /* Read by group */
#define TUEXEC  00100 /* Execute/search by owner */
#define TUWRITE 00200 /* Write by owner special */
#define TUREAD  00400 /* Read by owner */
#define TSVTX   01000 /* On directories, restricted deletion flag */
#define TSGID   02000 /* Set GID on execution */
#define TSUID   04000 /* Set UID on execution */

#endif
