#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar_buffered(char c, char *buffer, int *index);
int print_char(va_list args, char *buffer, int *index);
int print_string(va_list args, char *buffer, int *index);
int print_percent(char *buffer, int *index);
int print_int(va_list args, char *buffer, int *index);
int print_binary(va_list args, char *buffer, int *index);
int print_unsigned(va_list args, char *buffer, int *index);
int print_octal(va_list args, char *buffer, int *index);
int print_hex(va_list args, int upper_case, char *buffer, int *index);

#endif /* MAIN_H */

