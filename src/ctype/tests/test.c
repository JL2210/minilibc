/*
 *  Copyright (C) 2019 James Larrowe
 *
 *  This file is part of Minilibc.
 *
 *  Minilibc is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Minilibc is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Minilibc.  If not, see <https://www.gnu.org/licenses/>.
 */

#undef NDEBUG
#define DEBUG
#include <ctype.h>
#include <assert.h>

int main(void)
{
	int c[0xff][11] = {0};
	int ctr;
	for(ctr = 1; ctr <= 0xff; ctr++)
	{
		c[ctr-1][0] = isalnum(ctr);
		c[ctr-1][1] = isalpha(ctr);
		c[ctr-1][2] = isascii(ctr);
		c[ctr-1][3] = isblank(ctr);
		c[ctr-1][4] = isdigit(ctr);
		c[ctr-1][5] = islower(ctr);
		c[ctr-1][6] = isspace(ctr);
		c[ctr-1][7] = isupper(ctr);
		c[ctr-1][8] = toascii(ctr);
		c[ctr-1][9] = tolower(ctr);
		c[ctr-1][10] = toupper(ctr);
	}
}
