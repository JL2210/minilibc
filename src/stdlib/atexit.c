#include <stdlib.h>

#include "atexit.h"

int __register_atexit_func(struct atexit **head, atexit_func func)
{
    if((*head)->ctr >= MIN_ATEXIT_MAX)
    {
        struct atexit *tmp = calloc(1, sizeof(*tmp));

        if(!tmp)
            return -1;

        (*head)->next = tmp;
        (*head)->next->prev = (*head);
        *head = (*head)->next;
    }

    (*head)->func[(*head)->ctr++] = func;

    return 0;
}

int __call_atexit_funcs(struct atexit *head)
{
    while(head)
    {
        while(head->ctr--)
            head->func[head->ctr]();

        head = head->prev;
    }

    return 0;
}
