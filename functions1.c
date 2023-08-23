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

