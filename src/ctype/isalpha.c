#include <ctype.h>
#undef isalpha

int isalpha(int c)
{
    return (unsigned)(c | (1 << 5)) - 'a' < 26;
}
