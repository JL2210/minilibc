#include <ctype.h>

int (ispunct)(int c)
{
    return isprint(c) && c != ' ' && !isalnum(c);
}
