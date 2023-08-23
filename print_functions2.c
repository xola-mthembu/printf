#include "main.h"

/**
 * print_int_helper - Helper function to print an integer recursively
 * @n: Integer to print
 * Return: Number of characters printed
 */
int print_int_helper(int n)
{
int count = 0;
if (n / 10)
count += print_int_helper(n / 10);
_putchar(n % 10 + '0');
count++;
return (count);
}

/**
 * print_binary_helper - Helper function to print binary recursively
 * @n: Integer to print in binary
 * Return: Number of characters printed
 */
int print_binary_helper(unsigned int n)
{
int count = 0;
if (n / 2)
count += print_binary_helper(n / 2);
_putchar((n % 2) + '0');
count++;
return (count);
}

/**
 * print_unsigned - Prints an unsigned integer
 * @args: Argument list containing unsigned integer
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
if (n / 10)
count += print_unsigned_helper(n / 10);
_putchar(n % 10 + '0');
count++;
return (count);
}

/**
 * print_octal - Converts an unsigned int to octal
 * @args: Argument list containing unsigned int
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
count += print_octal_helper(n);
return (count);
}

