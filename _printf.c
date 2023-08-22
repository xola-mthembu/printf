#include "main.h"
#include <unistd.h>
#include <stddef.h>

/**
 * print_buffer - Prints buffer content.
 * @buffer: The buffer.
 * @buff_ind: The buffer index.
 */
void print_buffer(char buffer[], int *buff_ind)
{
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}

/**
 * handle_specifier - Handles specific specifiers.
 * @specifier: The specifier.
 * @list: Argument list.
 * @buffer: The buffer.
 * @buff_ind: Buffer index.
 */
void handle_specifier(char specifier, va_list list,
char buffer[], int *buff_ind)
{
if (specifier == 'c')
{
buffer[*buff_ind] = va_arg(list, int);
(*buff_ind)++;
}
else if (specifier == 's')
{
char *str = va_arg(list, char *);
while (*str)
{
buffer[*buff_ind] = *str++;
(*buff_ind)++;
}
}
else if (specifier == '%')
{
buffer[*buff_ind] = '%';
(*buff_ind)++;
}
}

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * ...
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
int i, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
int printed_chars = 0;

if (format == NULL)
return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
i++;
handle_specifier(format[i], list, buffer, &buff_ind);
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (printed_chars);
}

