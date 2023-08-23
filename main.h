#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

int _printf(const char *format, ...);
int _strlen(char *s);
void print_number(int n);
void print_binary(unsigned int n);
void print_unsigned(unsigned int n);
void print_octal(unsigned int n);
void print_hex(unsigned int n, int uppercase);
void write_buffer(char *buffer, int *index, char *str, int size);
void print_string_non_printable(char *str, char *buffer, int *index);
void print_pointer(void *ptr, char *buffer, int *index);
void get_flags(const char *format, int *i, flags_t *flags);

#endif /* MAIN_H */

