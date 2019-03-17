#ifndef _STDARG_H
#define _STDARG_H 1

struct
{
	int arg;
	void *ptr;
} _va_list;
typedef struct _va_list va_list;

#define va_start(x, y) (x = (va_list)calloc(1, sizeof(_va_list)); \
			x->arg = 0; \
			x->ptr = (void *)(((intptr_t)&y) + sizeof(y)))

#endif
