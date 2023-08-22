#include <stdio>
#include "main.h"
/**
 * print_number - Print an integer.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
if (n == 0)
{
_putchar('0');
return;
}
if (n < 0)
{
_putchar('-');
n = -n;
}
int reverse = 0;
while (n > 0)
{
reverse = reverse * 10 + n % 10;
n /= 10;
}
while (reverse > 0)
{
_putchar(reverse % 10 + '0');
reverse /= 10;
}
}
/**
 * print_int - Print an integer (d or i conversion specifier).
 * @args: The va_list containing the integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args)
{
int n = va_arg(args, int);
int printed_chars = 0;
if (n == 0)
{
_putchar('0');
printed_chars++;
}
else
{
if (n < 0)
{
