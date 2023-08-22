#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Prints a formatted string to the standard output
 * @format: The format string containing directives
 * @...: Additional arguments to be printed
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
int buff_ind = 0;
va_list list;
va_start(list, format);
for (int i = 0; format[i]; i++)
{
if (format[i] != '%')
{
write(1, &format[i], 1);
buff_ind++;
}
}
va_end(list);
return (buff_ind);
}
