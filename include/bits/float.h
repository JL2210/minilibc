#ifndef _FLOAT_H
# error "Never include <bits/float.h> directly; use <float.h> instead."
#endif

#if defined(__x86_64__) || defined(__i386__)
# define FLT_MIN 1.17549435082228750796873653722224568e-38F
# define FLT_MAX 3.40282346638528859811704183484516925e+38F
# define DBL_MIN ((double)2.22507385850720138309023271733240406e-308L)
# define DBL_MAX ((double)1.79769313486231570814527423731704357e+308L)
# define LDBL_MIN 3.36210314311209350626267781732175260e-4932L
# define LDBL_MAX 1.18973149535723176502126385303097021e+4932L
# define FLT_MANT_DIG 23
# define DBL_MANT_DIG 52
# define LDBL_MANT_DIG 64
#else
# error "no float macros for your system"
#endif
