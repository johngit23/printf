#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
void print_char(va_list arg);
void print_string(va_list arg);
void print_percent(__attribute__((unused))va_list arg);
void print_int(va_list arg);
void print_unsigned(va_list arg);
void print_octal(va_list arg);
void print_hex(va_list arg);
void print_hex_upper(va_list arg);
void print_binary(va_list arg);

#endif /* MAIN_H */
