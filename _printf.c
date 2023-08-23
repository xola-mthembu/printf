#include "main.h"
#include <unistd.h>

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
if (format[i] == '%' && (format[i + 1] == 'c'
|| format[i + 1] == 's' || format[i + 1] == '%'))
{
i++;
switch (format[i])
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
/* Implementation for string goes here */
break;
case '%':
count += _putchar('%');
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
