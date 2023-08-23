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
char buffer[1024];
int index = 0;

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
case 'd':
case 'i':
print_number(va_arg(args, int));
count += _strlen(buffer);
break;
case 'u':
print_unsigned(va_arg(args, unsigned int));
break;
case 'o':
print_octal(va_arg(args, unsigned int));
break;
case 'x':
print_hex(va_arg(args, unsigned int), 0);
break;
case 'X':
print_hex(va_arg(args, unsigned int), 1);
break;
case 'S':
print_string_non_printable(va_arg(args, char *), buffer, &index);
break;
case 'p':
print_pointer(va_arg(args, void *), buffer, &index);
break;
}
i++;
}
else
{
count += write_buffer(buffer, &index, &format[i], 1);
}
i++;
}
if (index > 0)
write(1, buffer, index);
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
