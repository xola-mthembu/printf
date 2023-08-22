#include "main.h"
/**
 * _printf - Our custom printf function.
 * @format: Format string containing the text and format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list args;
va_start(args, format);
int i = 0;
while (format && format[i])
{
if (format[i] != '%')
{
_putchar(format[i]);
printed_chars++;
}
else
{
i++;
if (format[i] == 'd' || format[i] == 'i')
printed_chars += print_int(args);
}
i++;
}
va_end(args);
return (printed_chars);
}
/**
 * _putchar - Write a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, return the number of characters written.
 *         On error, return -1.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
_printf("Hello, %d!\n", 12345);
return (0);
}
