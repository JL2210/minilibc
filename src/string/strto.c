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

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16

#define IS_BETWEEN_A_AND_F(x) (between_a_and_f = (x >= 'a' && x <= 'f'))
#define GREATER(x,y) ((x) > (y) ? (x) : (y))

int __base_str(char *str);

long long __strto(const char *str, char **endptr, int base)
{
    int c;
    long long len,
              ctr,
              ret = 0,
              power = 1;
    bool is_negative = false,
         between_a_and_f;
    const char *old_str = str;

    if(!str) goto invalid;

    len = strlen(str);
    if(!len)
        goto invalid;

    while(isspace(*str)) str++;
    if(*str == '-')
    {
        is_negative = true;
        str++;
    }
    else if(*str == '+')
    {
        str++;
    }

    if(strncasecmp("0x", str, 2))
    {
        if(!base) base = BASE_HEX;
        else if(base != BASE_HEX) goto invalid;
        str += 2;
    }

    len = strlen(str);
    if(!len)
        goto invalid;

    if(!base)
    {
        base = __base_str(str);
    }

    for(ctr = len - 1; ctr >= 0; ctr--, power *= base)
    {
        if(!IS_BETWEEN_A_AND_F(str[ctr]) && !isdigit(str[ctr]))
        {
            if(endptr) *(const char **)endptr = str + ctr;
            break;
        }
        if(!between_a_and_f) c = '0';
        else if(base != BASE_HEX) goto invalid;
        else c = 'a' - 10;
        ret += (str[ctr] - c) * power;
    }

    return is_negative ? -ret : ret;
invalid:
    errno = EINVAL;
    return 0;
}

int __base_str(char *str)
{
    int base = BASE_DEC;
    size_t ctr, len = strlen(str);
    bool between_a_and_f;

    for(ctr = 0; ctr < len; ctr++)
    {
        if(IS_BETWEEN_A_AND_F(str[ctr]))
            base = BASE_HEX;
    }
}

long long strtoll(const char *str, char **endptr, int base)
{
    return (long long)__strto(str, endptr, base);
}

unsigned long long strtoull(const char *str, char **endptr, int base)
{
    return (unsigned long long)__strto(str, endptr, base);
}

long strtol(const char *str, char **endptr, int base)
{
    return (long)__strto(str, endptr, base);
}

unsigned long strtoul(const char *str, char **endptr, int base)
{
    return (unsigned long)__strto(str, endptr, base);
}
