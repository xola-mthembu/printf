#include "main.h"

/**
 * print_string_non_printable - Prints a string and non-printable
 * characters are printed as \x followed by the ASCII value in hex.
 * @str: The string to print.
 * @buffer: The buffer to write to.
 * @index: The current buffer index.
 */
void print_string_non_printable(char *str, char *buffer, int *index)
{
int i;
char hex_base[] = "0123456789ABCDEF";
char hex[3];

for (i = 0; str[i]; i++)
{
if (str[i] > 0 && (str[i] < 32 || str[i] >= 127))
{
hex[0] = hex_base[(str[i] / 16) % 16];
hex[1] = hex_base[str[i] % 16];
hex[2] = '\0';
write_buffer(buffer, index, "\\x", 2);
write_buffer(buffer, index, hex, 2);
}
else
{
write_buffer(buffer, index, &str[i], 1);
}
}
}
/**
 * print_pointer - Prints the address of a pointer.
 * @ptr: The pointer whose address to print.
 * @buffer: The buffer to write to.
 * @index: The current buffer index.
 */
void print_pointer(void *ptr, char *buffer, int *index)
{
unsigned long int address = (unsigned long int)ptr;
char *hex_base = "0123456789abcdef";
char hex[9];
int i = 0;

if (address == 0)
{
write_buffer(buffer, index, "(nil)", 5);
return;
}

while (address > 0)
{
hex[i++] = hex_base[address % 16];
address /= 16;
}
hex[i] = '\0';

write_buffer(buffer, index, "0x", 2);
for (int j = i - 1; j >= 0; j--)
write_buffer(buffer, index, &hex[j], 1);
}

