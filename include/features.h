#ifndef _FEATURES_H
#define _FEATURES_H 1

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__GNUC__) && !defined(__TINYC__)
# define __attribute__(x)
# define __extension__
#endif

#if __STDC_VERSION__ < 201112L
# define _Noreturn __attribute__((__noreturn__))
#endif

#if __STDC_VERSION__ < 199901L
# define inline /* */
#endif

#ifdef __cplusplus
}
#endif

#endif
