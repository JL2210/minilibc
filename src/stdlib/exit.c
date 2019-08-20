#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>

#define MIN_ATEXIT_MAX 32

typedef void (*atexit_func_t)(void);

struct atexit {
	struct atexit *prev;
	atexit_func_t func[MIN_ATEXIT_MAX];
	int8_t ctr;
	struct atexit *next;
};
static struct atexit list[1], *head = list;

int atexit(atexit_func_t func)
{
    if(head->ctr >= MIN_ATEXIT_MAX)
    {
        struct atexit *tmp = calloc(1, sizeof(*tmp));
        if(!tmp) return -1;
        head->next = tmp;
        head->next->prev = head;
        head = head->next;
    }
    head->func[head->ctr++] = func;
    return 0;
}

_Noreturn void exit(int ret)
{
    while(head)
    {
        while(head->ctr--)
            head->func[head->ctr]();
        head = head->prev;
    }

    fflush(NULL);
    _exit(ret);
}

_Noreturn void _Exit(int a)
{
    _exit(a);
}
