#include "main.h"

/**
 * print_unsigned_helper - Helper function to print unsigned int recursively
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_unsigned_helper(unsigned int n)
{
int count = 0;
if (n / 10)
count += print_unsigned_helper(n / 10);
_putchar(n % 10 + '0');
count++;
return (count);
}

/**
 * print_octal_helper - Helper function to print octal recursively
 * @n: Integer to print in octal
 * Return: Number of characters printed
 */
int print_octal_helper(unsigned int n)
{
int count = 0;
if (n / 8)
count += print_octal_helper(n / 8);
_putchar((n % 8) + '0');
count++;
return (count);
}

/**
 * print_hex - Converts an unsigned int to hexadecimal
 * @args: Argument list containing unsigned int
 * @upper_case: Determines if the hex should be printed in uppercase
 * Return: Number of characters printed
 */
int print_hex(va_list args, int upper_case)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
count += print_hex_helper(n, upper_case);
return (count);
}

/**
 * print_hex_helper - Helper function to print hexadecimal recursively
 * @n: Integer to print in hexadecimal
 * @upper_case: Determines if the hex should be printed in uppercase
 * Return: Number of characters printed
 */
int print_hex_helper(unsigned int n, int upper_case)
{
int count = 0;
char c;
if (n / 16)
count += print_hex_helper(n / 16, upper_case);
c = (n % 16 < 10) ? (n % 16 + '0') : (n % 16 - 10 + (upper_case ? 'A' : 'a'));
_putchar(c);
count++;
return (count);
}

