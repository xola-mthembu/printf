#include "main.h"

/**
 * print_S - Prints a string, with non-printable characters replaced
 * @args: Argument list containing string
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_S(va_list args, char *buffer, int *index)
{
int i, count = 0;
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] > 0 && (str[i] < 32 || str[i] >= 127))
{
_putchar_buffered('\\', buffer, index);
_putchar_buffered('x', buffer, index);
count += print_hex_char((unsigned char)str[i], buffer, index);
}
else
{
_putchar_buffered(str[i], buffer, index);
}
count++;
}
return (count);
}

/**
 * print_hex_char - Helper function to print a char in hexadecimal
 * @c: Character to print in hexadecimal
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_hex_char(unsigned char c, char *buffer, int *index)
{
int count = 0;
char hex_val;

if (c / 16)
{
hex_val = (c / 16 < 10) ? (c / 16 + '0') : (c / 16 - 10 + 'A');
_putchar_buffered(hex_val, buffer, index);
count++;
}
hex_val = (c % 16 < 10) ? (c % 16 + '0') : (c % 16 - 10 + 'A');
_putchar_buffered(hex_val, buffer, index);
count++;

return (count);
}

