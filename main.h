#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * struct flags - flags
 * @space: space ' '
 * @plus: plus '+'
 * @hash: '#'
 */
typedef struct flags
{
	int space;
	int plus;
	int hash;
} flags;
/**
 * struct func_man - Struct op
 *
 * @fmt: formatted string
 * @f: The function associated
 */
typedef struct func_man
{
	char fmt;
	int (*f)(va_list, flags, char);
} func_man;

int _putchar(char c);
int (*spec_func(char fmt))(va_list, flags, char);
int print_char(va_list args, flags flags, char mod);
int print_string(va_list args, flags flags, char mod);
int _printf(const char *format, ...);
int print_int(va_list args, flags flags, char mod);
int print_bin(va_list args, flags flags, char mod);
int print_oct(va_list args, flags flags, char mod);
int print_unsigned(va_list args, flags flags, char mod);
int print_HEX(va_list args, flags flags, char mod);
int print_hex(va_list args, flags flags, char mod);
int print_S(va_list args, flags flags, char mod);
int print_ptr(va_list args, flags flags, char mod);
int prints(char *s);
int print_unknown(flags, char);
int print_num(unsigned long n);
int printflag(flags flags);
int print0x(void);
int print0X(void);
int printx(unsigned long n);
int printX(unsigned long n);
char *num2str(unsigned long n, int b);
int num_len(unsigned long n, int b);
char *num2STR(unsigned long n, int b);
long _abs(long n);
#endif
