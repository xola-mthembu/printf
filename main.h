#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int handle_specifier(char specifier, va_list args, char *buffer);

#endif /* MAIN_H */

