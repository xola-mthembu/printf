#include <stdio.h>
#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
int len;
len = _printf("Let's try to printf a simple sentence.\n");
_printf("Length: [%d]\n", len);
return (0);
}
