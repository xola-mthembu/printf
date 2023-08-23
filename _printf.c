#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: Number of characters printed (1)
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _printf - Our custom printf function
 * @format: The format string
 * @...: The values to format and print
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
unsigned int i = 0;

if (!format)
return (-1);

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_string(args);
break;
case '%':
count += print_percent();
break;
case 'd':
case 'i':
count += print_int(args);
break;
}
}
else
count += _putchar(format[i]);
i++;
}

va_end(args);

return (count);
}

