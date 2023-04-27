#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUF_SIZE_All 1024
/**
 * struct all_flag -  show the  struct containing pointers to functions
 *
 * @c: format
 * @pntr: show pointer to function that  assosciated
 */
struct all_flag
{
	char c;
	int (*pntr)(va_list);
};

/**
 * typedef struct all_flag dif - struct definition
 *
 * @all_flag: format only
 * @dif: function assosciated to difintion
 */

typedef struct all_flag dif;

int _printf(const char *form, ...);
int _strlen(char *s);

/*Funtions to pntr chars and strings*/
int handle_print(const char *format, int *i, va_list list);
int p_char(va_list list);
int p_string(va_list list);
int _putchar(char c);
int p_37(va_list list);
/* Functions to pntr numbers*/
int p_int(va_list list);
/*end*/
#endif
