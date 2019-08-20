#ifndef _CTYPE_H
#define _CTYPE_H 1

#include <features.h>

#define __need_locale_t

#include <bits/alldefs.h>

#define _toupper(x) ((x) & ~(1 << 5))
#define _tolower(x) ((x) | (1 << 5))
/*
#define isdigit(x) ((unsigned)(x) - '0' < 10)
#define isupper(x) ((unsigned)(x) - 'A' < 26)
#define islower(x) ((unsigned)(x) - 'a' < 26)
#define isalpha(x) (islower(_tolower((x))))
#define isalnum(x) (isalpha((x)) || isdigit((x)))
#define isascii(x) (!((x) & (1 << 7)))
#define isblank(x) ((x) == ' ' || (x) == '\t')
#define isspace(x) ((x) == ' ' || (unsigned)(x) - '\t' < 5)
#define toascii(x) ((x) & ~(1 << 7))
#define tolower(x) (isupper((x)) ? _tolower((x)) : (x))
#define toupper(x) (islower((x)) ? _toupper((x)) : (x))
*/

#ifdef __cplusplus
extern "C" {
#endif

extern int (isdigit)(int);
extern int (isupper)(int);
extern int (islower)(int);
extern int (isalpha)(int);
extern int (isalnum)(int);
extern int (isascii)(int);
extern int (isblank)(int);
extern int (isspace)(int);
extern int (toascii)(int);
extern int (tolower)(int);
extern int (toupper)(int);

#ifdef __cplusplus
}
#endif

#endif
