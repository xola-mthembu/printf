#include "main.h"
#include <unistd.h>

/**
 * write_buffer - Writes characters to the buffer and flushes when full.
 * @buffer: The buffer to write to.
 * @index: The current buffer index.
 * @str: The string to write.
 * @size: The size of the string to write.
 */
void write_buffer(char *buffer, int *index, char *str, int size)
{
int i;

for (i = 0; i < size; i++)
{
buffer[*index] = str[i];
(*index)++;

if (*index == 1024)
{
write(1, buffer, *index);
*index = 0;
}
}
}

