#include <string.h>
#include <stdio.h>

int main(void)
{
	unsigned char ch[] = { 0, 3, 7, 255 }, *p1, *p2, *p3, *p4;
	int r1, r2, r3, r4;
	p1 = memchr(ch, 7, sizeof(ch));
	p2 = memchr(ch, 255, sizeof(ch));
	p3 = memchr(ch, 4, sizeof(ch));
	p4 = memchr(ch, 256, sizeof(ch));
	r1 = (*p1 == 7);
	r2 = (*p2 == 255);
	r3 = (p3 == (unsigned char *)NULL);
	r4 = (*p4 == (unsigned char)256);
	return r1 && r2 && r3 && r4;
}
