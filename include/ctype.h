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

#ifndef CTYPE_H
#define CTYPE_H 1

#include <features.h>

extern int isdigit(int);
extern int isalnum(int);
extern int isalpha(int);
extern int isascii(int);
extern int isblank(int);
extern int isdigit(int);
extern int islower(int);
extern int isspace(int);
extern int isupper(int);
extern int toascii(int);
extern int tolower(int);
extern int toupper(int);

#endif
