#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Our custom printf function
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
int i, count = 0, buffer_index = 0;
char buffer[1024] = {0};
char flags = '\0', length = '\0';
int width = 0;
va_list args;
va_start(args, format);
for (i = 0; format && format[i]; i++)
{
if (format[i] == '%' && (format[i + 1] == '+' || format[i + 1] == ' ' || format[i + 1] == '#'))
{
flags = format[i + 1];
i++;
}
if (format[i] == '%' && (format[i + 1] == 'l' || format[i + 1] == 'h'))
{
length = format[i + 1];
i++;
}
if (format[i] == '%' && format[i + 1] >= '0' && format[i + 1] <= '9')
{
while (format[i + 1] >= '0' && format[i + 1] <= '9')
{
width = width * 10 + (format[i + 1] - '0');
i++;
}
}
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
count += print_int(args, flags, length, width, buffer, &buffer_index);
break;
case 'b':
count += print_binary(args, buffer, &buffer_index);
break;
case 'u':
count += print_unsigned(args, flags, width, buffer, &buffer_index);
break;
case 'o':
count += print_octal(args, flags, width, buffer, &buffer_index);
break;
case 'x':
case 'X':
count += print_hex(args, format[i] == 'X', flags, width, buffer, &buffer_index);
break;
case 'p':
count += print_address(args, buffer, &buffer_index);
break;
default:
break;
}
flags = length = '\0';
width = 0;
}
else
{
count += _putchar_buffered(format[i], buffer, &buffer_index);
}
}
write(1, buffer, buffer_index);
va_end(args);
return (count);
}

/**
 * _putchar_buffered - Writes a character to a buffer
 * @c: The character
 * @buffer: The buffer to write to
 * @index: The index in the buffer to write at
 * Return: Always 1
 */
int _putchar_buffered(char c, char *buffer, int *index)
{
if (*index >= 1024)
{
write(1, buffer, *index);
*index = 0;
}
buffer[(*index)++] = c;
return (1);
}

