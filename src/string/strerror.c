#include <string.h>
#include "strerror.h"

char *strerror(int err)
{
	return (char *)(strerrors[err-1].description);
}
