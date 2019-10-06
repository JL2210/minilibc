/* Grumble... This file isn't standardized but
 * it's widely used (and incorrectly at that).
 */
#ifndef _SYS_CDEFS_H
#define _SYS_CDEFS_H 1

#include <features.h>

#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#endif
