#include "main.h"
#include <unistd.h>


/**
 * _strlen - Returns the length of a string.
 * @s: The string to be measured.
 * Return: The length of the string.
 */
int _strlen(char *s); /* Declare _strlen function */

int _strlen(char *s)
{
int length = 0;

while (*s)
{
length++;
s++;
}

return (length);
}

/**
 * _printf - Produces output according to a format.
 * @format: A string containing the desired format.
 * @...: A variable number of arguments to be formatted.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
unsigned int i = 0;
char c; /* Temporary variable to hold a character */

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'
|| format[i + 1] == '%'))
{
if (format[i + 1] == 'c')
{
c = va_arg(args, int);
count += write(1, &c, 1);
}
else if (format[i + 1] == 's')
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
count += write(1, str, _strlen(str));
}
else
{
c = '%';
count += write(1, &c, 1);
}
i++;
}
else
{
count += write(1, &format[i], 1);
}
i++;
}

va_end(args);

return (count);
}

