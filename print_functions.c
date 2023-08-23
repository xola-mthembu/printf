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

