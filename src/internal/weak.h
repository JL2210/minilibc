#ifndef WEAK_H
#define WEAK_H 1

#ifdef __GNUC__
# define weak_alias(x, y) extern __typeof(y) x __attribute__((__weak__, __alias__(#y)))
#else
/* Not sure what to do here... */
#endif

#endif
