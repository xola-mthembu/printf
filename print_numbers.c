#include "main.h"
#include <limits.h>

/**
 * print_int - Prints an integer
 * @args: Argument list containing integer
 * @flags: Character indicating the flags to apply
 * @length: Character indicating the length modifier
 * @width: Minimum field width
 * @precision: The precision
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_int(va_list args, char flags,
char length, int width, int precision, char *buffer, int *index)
{
long int n;
int count = 0;
if (length == 'l')
n = va_arg(args, long int);
else if (length == 'h')
n = (short int)va_arg(args, int);
else
n = va_arg(args, int);
if (n >= 0 && (flags == '+' || flags == ' '))
count += _putchar_buffered(flags, buffer, index);
if (n == INT_MIN)
{
count += _putchar_buffered('-', buffer, index);
count += print_unsigned_int(INT_MAX + 1U, buffer, index);
}
else if (n < 0)
{
n = -n;
count += _putchar_buffered('-', buffer, index);
count += print_unsigned_int(n, buffer, index);
}
else
{
count += print_unsigned_int(n, buffer, index);
}
while (count < width)
{
count += _putchar_buffered(' ', buffer, index);
}
return (count);
}

/**
 * print_octal - Prints an unsigned integer
 * @n: The unsigned integer
 * @flags: Character indicating the flags to apply ('#', or '\0')
 * @width: Minimum field width
 * @precision: The precision
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_octal(unsigned int n, char flags, int width,
int precision, char *buffer, int *index)
{
int count = 0;
if (flags == '#' && n != 0)
count += _putchar_buffered('0', buffer, index);
if (n / 8)
count += print_octal(n / 8, flags, width, precision, buffer, index);
count += _putchar_buffered(n % 8 + '0', buffer, index);
while (count < width)
{
count += _putchar_buffered(' ', buffer, index);
}
return (count);
}

/**
 * print_unsigned - Prints an unsigned integer
 * @args: Argument list containing integer
 * @flags: Character indicating the flags to apply
 * @width: Minimum field width
 * @precision: The precision
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_unsigned(va_list args, char flags,
int width, int precision, char *buffer, int *index)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
if (flags == '+' || flags == ' ')
count += _putchar_buffered(flags, buffer, index);
count += print_unsigned_int(n, buffer, index);
while (count < width)
{
count += _putchar_buffered(' ', buffer, index);
}
return (count);
}

/**
 * print_hex - Prints an unsigned integer
 * @n: The unsigned integer
 * @upper_case: Flag to print in upper case
 * @flags: Character indicating the flags to apply ('#', or '\0')
 * @width: Minimum field width
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_hex(unsigned int n, int upper_case,
char flags, int width, char *buffer, int *index)
{
int count = 0;
char c;
if (flags == '#' && n != 0)
{
count += _putchar_buffered('0', buffer, index);
count += _putchar_buffered(upper_case ? 'X' : 'x', buffer, index);
}
if (n / 16)
count += print_hex(n / 16, upper_case, flags, width, buffer, index);
c = (n % 16 < 10) ? (n % 16 + '0') : (n % 16 - 10 + (upper_case ? 'A' : 'a'));
count += _putchar_buffered(c, buffer, index);
while (count < width)
{
count += _putchar_buffered(' ', buffer, index);
}
return (count);
}

/**
 * print_unsigned_int - Helper function
 * @n: Unsigned integer to print
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_unsigned_int(unsigned int n, char *buffer, int *index)
{
int count = 0;
if (n / 10)
count += print_unsigned_int(n / 10, buffer, index);
count += _putchar_buffered(n % 10 + '0', buffer, index);
return (count);
}

