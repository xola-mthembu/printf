#include "main.h"

/**
 * print_char - Prints a character
 * @args: Argument list containing character
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string
 * @args: Argument list containing string
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
int i;
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
for (i = 0; str[i] != '\0'; i++)
_putchar(str[i]);
return (i);
}

/**
 * print_percent - Prints a percent sign
 * Return: Number of characters printed
 */
int print_percent(void)
{
return (_putchar('%'));
}

/**
 * print_int - Prints an integer
 * @args: Argument list containing integer
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
int n = va_arg(args, int);
int count = 0;
if (n < 0)
{
_putchar('-');
count++;
n = -n;
}
if (n / 10)
count += print_int_helper(n / 10);
_putchar(n % 10 + '0');
count++;
return (count);
}

/**
 * print_binary - Converts an unsigned int to binary
 * @args: Argument list containing unsigned int
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
if (n == 0)
{
_putchar('0');
return (1);
}
count += print_binary_helper(n);
return (count);
}

