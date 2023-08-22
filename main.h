#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#define BUFF_SIZE 1024
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
void handle_specifier(char specifier, va_list list, char buffer[], int *buff_ind);
#endif /* MAIN_H */

