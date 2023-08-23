#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Prototype for the custom _printf function */
int _printf(const char *format, ...);

/* Prototypes for functions to print individual specifiers */
int print_char(va_list args, char *buffer, int *index);
int print_string(va_list args, char *buffer, int *index);
int print_S(va_list args, char *buffer, int *index);
int print_percent(char *buffer, int *index);
int print_int(va_list args, char flags, char *buffer, int *index);
int print_binary(va_list args, char *buffer, int *index);
int print_unsigned(va_list args, char flags, char *buffer, int *index);
int print_octal(va_list args, char flags, char *buffer, int *index);
int print_hex(va_list args, int upper_case, char flags, char *buffer, int *index);
int print_address(va_list args, char *buffer, int *index);

/* Helper function to print a character to a buffer */
int _putchar_buffered(char c, char *buffer, int *index);

/* Additional prototypes depending on task requirements */

#endif /* MAIN_H */

