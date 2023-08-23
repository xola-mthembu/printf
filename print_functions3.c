#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @args: Argument list containing unsigned integer
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_unsigned(va_list args, char *buffer, int *index)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
if (n / 10)
count += print_unsigned_helper(n / 10, buffer, index);
_putchar_buffered(n % 10 + '0', buffer, index);
count++;
return (count);
}

/**
 * print_unsigned_helper - Helper function to print unsigned int recursively
 * @n: Unsigned integer to print
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_unsigned_helper(unsigned int n, char *buffer, int *index)
{
int count = 0;
if (n / 10)
count += print_unsigned_helper(n / 10, buffer, index);
_putchar_buffered(n % 10 + '0', buffer, index);
count++;
return (count);
}

/**
 * print_octal - Converts an unsigned int to octal
 * @args: Argument list containing unsigned int
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_octal(va_list args, char *buffer, int *index)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
count += print_octal_helper(n, buffer, index);
return (count);
}

/**
 * print_octal_helper - Helper function to print octal recursively
 * @n: Integer to print in octal
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_octal_helper(unsigned int n, char *buffer, int *index)
{
int count = 0;
if (n / 8)
count += print_octal_helper(n / 8, buffer, index);
_putchar_buffered((n % 8) + '0', buffer, index);
count++;
return (count);
}

/**
 * print_hex - Converts an unsigned int to hexadecimal
 * @args: Argument list containing unsigned int
 * @upper_case: Determines if the hex should be printed in uppercase
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_hex(va_list args, int upper_case, char *buffer, int *index)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
count += print_hex_helper(n, upper_case, buffer, index);
return (count);
}

/**
 * print_hex_helper - Helper function to print hexadecimal recursively
 * @n: Integer to print in hexadecimal
 * @upper_case: Determines if the hex should be printed in uppercase
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_hex_helper(unsigned int n, int upper_case, char *buffer, int *index)
{
int count = 0;
char c;
if (n / 16)
count += print_hex_helper(n / 16, upper_case, buffer, index);
c = (n % 16 < 10) ? (n % 16 + '0') : (n % 16 - 10 + (upper_case ? 'A' : 'a'));
_putchar_buffered(c, buffer, index);
count++;
return (count);
}

