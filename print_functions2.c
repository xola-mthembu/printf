#include "main.h"

/**
 * print_int - Prints an integer
 * @args: Argument list containing integer
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_int(va_list args, char *buffer, int *index)
{
int n = va_arg(args, int);
int count = 0;
if (n < 0)
{
_putchar_buffered('-', buffer, index);
count++;
n = -n;
}
if (n / 10)
count += print_int_helper(n / 10, buffer, index);
_putchar_buffered(n % 10 + '0', buffer, index);
count++;
return (count);
}

/**
 * print_int_helper - Helper function to print an integer recursively
 * @n: Integer to print
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_int_helper(int n, char *buffer, int *index)
{
int count = 0;
if (n / 10)
count += print_int_helper(n / 10, buffer, index);
_putchar_buffered(n % 10 + '0', buffer, index);
count++;
return (count);
}

/**
 * print_binary - Converts an unsigned int to binary
 * @args: Argument list containing unsigned int
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_binary(va_list args, char *buffer, int *index)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
if (n == 0)
{
_putchar_buffered('0', buffer, index);
return (1);
}
count += print_binary_helper(n, buffer, index);
return (count);
}

/**
 * print_binary_helper - Helper function to print binary recursively
 * @n: Integer to print in binary
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_binary_helper(unsigned int n, char *buffer, int *index)
{
int count = 0;
if (n / 2)
count += print_binary_helper(n / 2, buffer, index);
_putchar_buffered((n % 2) + '0', buffer, index);
count++;
return (count);
}

