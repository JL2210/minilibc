#ifndef _STDBOOL_H
#define _STDBOOL_H 1

#ifndef __cplusplus
# define bool _Bool
# define true 1
# define false 0
#else
/* Some GCC extensions */
# define _Bool bool
# if __cplusplus < 201103L
#  define bool bool
#  define false false
#  define true true
# endif
#endif

#define __bool_true_false_are_defined 1

#endif
