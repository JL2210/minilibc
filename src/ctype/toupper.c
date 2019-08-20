#include <ctype.h>

int (toupper)(int c)
{
    return (unsigned)c - 'a' < 26 ? _toupper(c) : c;
}
