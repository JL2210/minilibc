#include <ctype.h>

int (tolower)(int c)
{
    return (unsigned)c - 'A' < 26 ? _tolower(c) : c;
}
