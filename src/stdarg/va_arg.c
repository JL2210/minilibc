#include <stdarg.h>

size_t *va_arg_c(va_list x, size_t y)
{
	intptr_t x_ptr = (intptr_t)x;
	x_ptr += y;
	x = (va_list)x_ptr;
	return (size_t *)x_ptr;
}
