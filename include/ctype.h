#ifndef _CTYPE_H
#define _CTYPE_H 1

#include <features.h>

#define __need_locale_t

#include <bits/defs.h>

#define _toupper(x) ((x)+('a'-'A'))
#define _tolower(x) ((x)+('A'-'a'))

__BEGIN_DECLS

int isalnum(int c);
int isalpha(int c);
int isascii(int c);
int isblank(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);
int toascii(int c);
int tolower(int c);
int toupper(int c);

__END_DECLS

#endif
