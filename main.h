#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BFR_SYZ 1024

/* FLAGS */
#define FLG_MINUS 1
#define FLG_PLUS 2
#define FLG_ZERO 4
#define FLG_HASH 8
#define FLG_SPACE 16

/* SIZES */
#define LONG_SYZ 2
#define SHORT_SYZ 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i,
va_list list, char buffr[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffr[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffr[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffr[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffr[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffr[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffr[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffr[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffr[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffr[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffr[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffr[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_ptr(va_list types, char buffr[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_str_rev(va_list types, char buffr[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_str_rot13(va_list types, char buffr[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffr[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffr[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffr[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffr[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int print_checker(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int conv_size_num(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
