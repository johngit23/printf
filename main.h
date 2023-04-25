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
