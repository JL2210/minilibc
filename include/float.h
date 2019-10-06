#ifndef _FLOAT_H
#define _FLOAT_H 1

#include <features.h>

#ifdef __GNUC__
# define FLT_MIN __FLT_MIN__
# define FLT_MAX __FLT_MAX__
# define DBL_MIN __DBL_MIN__
# define DBL_MAX __DBL_MAX__
# define LDBL_MIN __LDBL_MIN__
# define LDBL_MAX __LDBL_MAX__
# define FLT_MANT_DIG __FLT_MANT_DIG__
# define DBL_MANT_DIG __DBL_MANT_DIG__
# define LDBL_MANT_DIG __LDBL_MANT_DIG__
#else
# include <bits/float.h>
#endif

#endif
