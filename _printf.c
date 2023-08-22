#include "main.h"
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * @...: The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
unsigned int i = 0, count = 0;
va_list args;

va_start(args, format);
while (format && format[i])
{
if (format[i] == '%' && (format[i + 1] == 'c' ||
format[i + 1] == 's' || format[i + 1] == '%'))
{
switch (format[i + 1])
{
case 'c':
count += write(1, &(char[]){va_arg(args, int)}, 1);
break;
case 's':
count += write(1, va_arg(args, char *), _strlen(va_arg(args, char *)));
break;
case '%':
count += write(1, "%", 1);
break;
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
/**
 * _strlen - Calculate the length of a string.
 * @s: The string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
int length = 0;

while (s[length])
length++;
return (length);
}
