#include <ctype.h>

int (isalpha)(int c)
{
    return (unsigned)_tolower(c) - 'a' < 26;
}
