#include <ctype.h>

int (isxdigit)(int c)
{
    return isdigit(c) || (unsigned)_tolower(c) - 'a' < 6;
}
