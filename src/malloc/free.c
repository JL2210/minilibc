#include "malloc.h"

#include <stdlib.h>

void free(void *ptr)
{
	struct allocation_info *tmp_allinfo = __allocinfo;

	if(ptr == NULL) return;

	while(tmp_allinfo->prev != NULL)
		tmp_allinfo = tmp_allinfo->prev;

	while(tmp_allinfo && tmp_allinfo->start != ptr)
		tmp_allinfo = tmp_allinfo->next;

	if(!tmp_allinfo) return;

	tmp_allinfo->free = 1;
	return;
}
