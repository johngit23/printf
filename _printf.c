#include "main.h"
/**
 * _printf - prints out string and arguments
 * @format: string to pntr
 * Return: size of string -1 if fail
 */

int _printf(const char *format, ...)
{
	int i, uc = 0, p = 0;
	va_list list;

	if (!format)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			uc++;
		}
		else
		{
			i++;
			if (format[i])
				p = handle_print(format, &i, list);
			else
				p = -1;
			if (p == -1 && format[i])
			{
				p_37(list);
				uc++;
				i--;
			}
			else if (p == -1)
				return (-1);
			else if (p != -1)
				uc += p;
		}
	}
	va_end(list);
	return (uc);
}

/**
 * handle_print - takes care of printing
 * @format: pointer to format string
 * @i: index of char
 * @list: arguments
 * Return: size of pntr or -1 if fail
 */

int handle_print(const char *format, int *i, va_list list)
{
	dif function[] = {
		{'c', p_char}, {'s', p_string}, {'%', p_37}
		, {'i', p_int}, {'d', p_int}, {'\0', NULL}};
	int j;

	for (j = 0; j < 6; ++j)
	{
		if (function[j].c == format[*i])
			return (function[j].pntr(list));
	}
	return (-1);
}
