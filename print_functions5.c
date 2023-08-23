#include "main.h"

/**
 * print_address - Prints the address of an argument
 * @args: Argument list containing the pointer
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_address(va_list args, char *buffer, int *index)
{
unsigned long int address = (unsigned long int)va_arg(args, void *);
int count = 0;

if (address == 0)
{
count += _putchar_buffered('(', buffer, index);
count += _putchar_buffered)'0', buffer, index);
count += _putchar_buffered('x', buffer, index);
count += _putchar_buffered('0', buffer, index);
count += _putchar_buffered(')', buffer, index);
}
else
{
count += _putchar_buffered('0', buffer, index);
count += _putchar_buffered('x', buffer, index);
count += print_hex_address(address, buffer, index);
}

return (count);
}

/**
 * print_hex_address - Helper function to print hexadecimal address
 * @n: Address value
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_hex_address(unsigned long int n, char *buffer, int *index)
{
int count = 0;
char c;

if (n / 16)
count += print_hex_address(n / 16, buffer, index);
c = (n % 16 < 10) ? (n % 16 + '0') : (n % 16 - 10 + 'a');
count += _putchar_buffered(c, buffer, index);

return (count);
}

