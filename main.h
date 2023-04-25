#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct flags - flags struct
 * @plus: plus flag
 * @space: space flag
 * @hash: hash flag
 */
typedef struct flags
{
	int plus, space, hash;
} flags_t;

/**
 * struct print_handler - choose func
 * @ch: spec. char
 * @f: func. ptr
 */
typedef struct print_handler
{
	char ch;
	int (*f)(va_list, flags_t *);
} p_h;

/*Main function*/
int _printf(const char *format, ...);

/*flags_set.c*/
int set_flag(char flag_specifier, flags_t *flags);

/*print_char.c*/
int _print_char(char c);
int _print_str(char *str);

/*string_fun.c*/
int print_rev(va_list l, flags_t *f);
int print_rot13(va_list l, flags_t *f);
int print_percent(va_list l, flags_t *f);
int print_S(va_list l, flags_t *f);

/*num_funs.c*/
int count_digit(int i);
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);

/*conv_to_str.c*/
char *convert(unsigned long int num, int base, int lowercase);

/*print.c*/
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/*ptr_add.c*/
int print_address(va_list l, flags_t *f);

/*base.c*/
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);
int print_hex(va_list l, flags_t *f);
int print_HEX(va_list l, flags_t *f);

/*print_fun.c*/
int (*get_print(char s))(va_list, flags_t *);

#endif
