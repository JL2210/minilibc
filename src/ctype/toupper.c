#include <ctype.h>
#undef toupper

int toupper(int c)
{
        return isupper(c) ? c : c & ~((1 << 5) | (1 << 7));
}
