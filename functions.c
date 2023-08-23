#include "main.h"
#include <unistd.h>

/**
 * print_number - Prints an integer as a string.
 * @n: The integer.
 */
void print_number(int n)
{
int divisor = 1, i = 0;
char buffer[10];

if (n < 0)
{
buffer[i++] = '-';
n = -n;
}
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

