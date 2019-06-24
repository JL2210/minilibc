#include <ctype.h>
#undef tolower

int tolower(int c)
{
        return islower(c) ? c : c | (1 << 5);
}
