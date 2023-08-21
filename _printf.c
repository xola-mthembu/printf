#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: Format string.
 *
 * Return: Number of printed characters.
 */
int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list args;
if (format == NULL)
return (-1);
va_start(args, format);
while (*format)
{
if (*format == '%' && *(format + 1) != '\0')
{
format++; /* Move past '%' */
if (*format == 'c')
printed_chars += _putchar(va_arg(args, int));
else if (*format == 's')
printed_chars += print_string(va_arg(args, char *));
else if (*format == '%')
printed_chars += _putchar('%');
else
_putchar('%'); /* Print invalid specifier as is */
}
else
{
_putchar(*format);
printed_chars++;
}
format++;
}
va_end(args);
return (printed_chars);
}
/**
 * print_buffer - Prints the buffer
 * @buffer: Array of characters to be printed.
 * @buff_ind: Index for the next character, represents length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
