#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define IS_BETWEEN_A_AND_F(x) (between_a_and_f = (x >= 'a' && x <= 'f'))

long long __strto(char *str, char **endptr, int base)
{
	int c;
        size_t len, ctr;
        long long power = 1, ret = 0;
        bool is_negative = 0, between_a_and_f;

        while(isspace(*str)) str++;

	len = strlen(str);

        for(ctr = 0; ctr < len; ctr++, power *= base)
        {
                if(!IS_BETWEEN_A_AND_F(str[ctr]) && !isdigit(str[ctr]))
		{
			if(endptr) *endptr = &str[ctr];
			break;
		}
                if(str[ctr] == '-')
                {
                        is_negative = 1;
                        continue;
                }
                if(!between_a_and_f) c = '0';
		else c = 'a' - 10;
                ret += (str[ctr] - c) * power;
        }

        return is_negative ? -ret : ret;
}

long long strtoll(char *str, char **endptr, int base)
{
	return (long long)__strto(str, endptr, base);
}

unsigned long long strtoull(char *str, char **endptr, int base)
{
	return (unsigned long long)__strto(str, endptr, base);
}

long strtol(char *str, char **endptr, int base)
{
	return (long)__strto(str, endptr, base);
}

unsigned long strtoul(char *str, char **endptr, int base)
{
	return (unsigned long)__strto(str, endptr, base);
}
