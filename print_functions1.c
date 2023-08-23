#include "main.h"

/**
 * print_char - Prints a character
 * @args: Argument list containing character
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_char(va_list args, char *buffer, int *index)
{
return (_putchar_buffered(va_arg(args, int), buffer, index));
}

/**
 * print_string - Prints a string
 * @args: Argument list containing string
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_string(va_list args, char *buffer, int *index)
{
int i;
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
for (i = 0; str[i] != '\0'; i++)
{
_putchar_buffered(str[i], buffer, index);
}
return (i);
}

/**
 * print_percent - Prints a percent sign
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_percent(char *buffer, int *index)
{
return (_putchar_buffered('%', buffer, index));
}

