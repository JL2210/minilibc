#ifndef CTYPE_H
#define CTYPE_H 1

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int isdigit(int);
extern int isalnum(int);
extern int isalpha(int);
extern int isascii(int);
extern int isblank(int);
extern int isdigit(int);
extern int islower(int);
extern int isspace(int);
extern int isupper(int);
extern int toascii(int);
extern int tolower(int);
extern int toupper(int);

#ifdef __cplusplus
}
#endif

#endif
