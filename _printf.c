#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar_buffered - Writes a character to buffer
 * @c: The character to print
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed (1)
 */
int _putchar_buffered(char c, char *buffer, int *index)
{
buffer[*index] = c;
(*index)++;
if (*index >= 1024)
{
write(1, buffer, *index);
*index = 0;
}
return (1);
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
char buffer[1024];
int count = 0;
int buffer_index = 0;
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
count += print_char(args, buffer, &buffer_index);
break;
case 's':
count += print_string(args, buffer, &buffer_index);
break;
case 'S':
count += print_S(args, buffer, &buffer_index);
break;
case '%':
count += print_percent(buffer, &buffer_index);
break;
case 'd':
case 'i':
count += print_int(args, buffer, &buffer_index);
break;
case 'b':
count += print_binary(args, buffer, &buffer_index);
break;
case 'u':
count += print_unsigned(args, buffer, &buffer_index);
break;
case 'o':
count += print_octal(args, buffer, &buffer_index);
break;
case 'x':
count += print_hex(args, 0, buffer, &buffer_index);
break;
case 'X':
count += print_hex(args, 1, buffer, &buffer_index);
break;
case 'p':
count += print_address(args, buffer, &buffer_index);
break;
}
}
else
{
count += _putchar_buffered(format[i], buffer, &buffer_index);
}
i++;
}

if (buffer_index > 0)
write(1, buffer, buffer_index);

va_end(args);

return (count);
}

