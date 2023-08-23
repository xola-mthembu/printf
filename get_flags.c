#include "main.h"

/**
 * get_flags - Parses the flag characters for non-custom conversion specifiers.
 * @format: The format string.
 * @i: The current index in the format string.
 * @flags: A structure to store the flags.
 */
void get_flags(const char *format, int *i, flags_t *flags)
{
while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
{
if (format[*i] == '+')
flags->plus = 1;
else if (format[*i] == ' ')
flags->space = 1;
else if (format[*i] == '#')
flags->hash = 1;
(*i)++;
}
}

