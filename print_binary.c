#include "main.h"

/**
 * print_binary - Prints an unsigned integer in binary
 * @args: Argument list containing unsigned integer
 * @buffer: Buffer to write to
 * @index: Index in buffer to write at
 * Return: Number of characters printed
 */
int print_binary(va_list args, char *buffer, int *index)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
if (n / 2)
count += print_binary(args, buffer, index);
count += _putchar_buffered(n % 2 + '0', buffer, index);
return (count);
}

