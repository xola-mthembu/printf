#include "main.h"
#include <unistd.h>

/**
 * print_binary - Prints an unsigned int as a binary number.
 * @n: The unsigned integer.
 */
void print_binary(unsigned int n)
{
unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
char buffer[33];
int i = 0;

while (mask > 0)
{
if (n & mask)
break;
mask >>= 1;
}
if (mask == 0)
buffer[i++] = '0';
while (mask > 0)
{
if (n & mask)
buffer[i++] = '1';
else
buffer[i++] = '0';
mask >>= 1;
}
buffer[i] = '\0';
write(1, buffer, _strlen(buffer));
}
/**
 * print_unsigned - Prints an unsigned integer as a string.
 * @n: The unsigned integer.
 */
void print_unsigned(unsigned int n)
{
unsigned int divisor = 1;
char buffer[10];
int i = 0;

while (n / divisor >= 10)
divisor *= 10;
while (divisor != 0)
{
buffer[i++] = '0' + (n / divisor) % 10;
n %= divisor;
divisor /= 10;
}
buffer[i] = '\0';
write(1, buffer, _strlen(buffer));
}

/**
 * print_octal - Prints an unsigned integer as an octal number.
 * @n: The unsigned integer.
 */
void print_octal(unsigned int n)
{
int i = 0;
char buffer[12];

while (n > 0)
{
buffer[i++] = '0' + (n % 8);
n /= 8;
}
buffer[i] = '\0';
for (int j = i - 1; j >= 0; j--)
write(1, &buffer[j], 1);
}

/**
 * print_hex - Prints an unsigned integer as a hexadecimal number.
 * @n: The unsigned integer.
 * @uppercase: If 1, print in uppercase. If 0, print in lowercase.
 */
void print_hex(unsigned int n, int uppercase)
{
int i = 0;
char buffer[9];
char *hex_base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

while (n > 0)
{
buffer[i++] = hex_base[n % 16];
n /= 16;
}
buffer[i] = '\0';
for (int j = i - 1; j >= 0; j--)
write(1, &buffer[j], 1);
}

