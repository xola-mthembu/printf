#include "main.h"

/**
* _strlen - Computes the length of a string.
* @s: The string to measure.
* Return: The length of the string.
*/
int _strlen(char *s)
{
int length = 0;
while (s[length])
length++;
return (length);
}

/**
* handle_specifier - Handles individual specifiers.
* @specifier: The specifier character.
* @args: The argument list.
* @buffer: The buffer to write to.
* Return: The number of characters added to the buffer.
*/
int handle_specifier(char specifier, va_list args, char *buffer)
{
char *s;
int length = 0, i; /* Declare 'i' at the beginning of the function */
switch (specifier)
{
case 'c':
buffer[0] = (char)va_arg(args, int);
length = 1;
break;
case 's':
s = va_arg(args, char *);
if (s == NULL)
s = "(null)";
length = _strlen(s);
for (i = 0; i < length; i++)
buffer[i] = s[i];
break;
case '%':
buffer[0] = '%';
length = 1;
break;
}
return (length);
}

/**
* _printf - Custom printf function.
* @format: The format string.
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int i, buff_ind = 0, printed_chars = 0;
char buffer[BUFF_SIZE] = {0};

va_start(args, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
{
write(1, buffer, buff_ind);
buff_ind = 0;
}
}
else
{
write(1, buffer, buff_ind);
buff_ind = 0;
buff_ind += handle_specifier(format[++i], args, &buffer[buff_ind]);
}
}

write(1, buffer, buff_ind);

va_end(args);

return (printed_chars);
}

