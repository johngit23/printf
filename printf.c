#include "main.h"
static unsigned int i, count;
static int value, checker, (*f)(va_list, flags, char);
static char mod;
/**
 * isflag - checks if a character is a flag
 * @c: char to check
 * Return: 1 if is flag 0 if not
 */

int isflag(char c)
{
	int j;
	char f[] = "+ #";

	for (j = 0; f[j]; j++)
	{
		if (c == f[j])
			return (1);
	}
	return (0);
}
/**
 * isspec - checks if a character is a specifier
 * @c: char to check
 * Return: 1 if is flag 0 if not
 */

int isspec(char c)
{
	int j;
	char s[] = "diucsSpoxX";

	for (j = 0; s[j]; j++)
	{
		if (c == s[j])
			return (1);
	}
	return (0);
}
/**
 * ismod - checks if a character is a modifier
 * @c: charcter to check
 * Return: 0 if not, 1 if it is
 */
int ismod(char c)
{
	char *mods = "lh";
	int j;

	for (j = 0; mods[j]; j++)
		if (mods[j] == c)
			return (1);
	return (0);
}

/**
 * getparams - checks if character is a flag or specifier and sets
 * the value of flag;
 * @fmt: string
 * @i: address of string index
 * @flg: flag pointer
 * @mod: modifier
 * Return: 1 flag found and specifier is good , returns 0 if neither
 * -1 if flag and nextchar is null or not specifier
 */
int getparams(const char *fmt, unsigned int *i, flags *flg, char *mod)
{
	int d = *i;

	*mod = 0;
	for (; isflag(fmt[d]); d++)
	{
		switch (fmt[d])
		{
		case '+':
			flg->plus = 1;
			break;
		case ' ':
			flg->space = 1;
			break;
		case '#':
			flg->hash = 1;
			break;
		}
	}
	if (ismod(fmt[d]))
	{
		*mod = fmt[d];
		d++;
	}
	*i = d;
	if (!isspec(fmt[d]) && fmt[d])
		return (0);
	if (isspec(fmt[d]))
		return (1);
	return (-1);
}
/**
 * _printf - prints a formated text with arguements passed
 * @format: formated string - formatting is optional
 * Return: Number of characters printed to screen
 */

int _printf(const char *format, ...)
{
	va_list args;
	flags flg = {0, 0, 0};

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0, count = 0; format[i] != 0; i++)
	{
		if (format[i] != '%')
			count += _putchar(format[i]);
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			checker = getparams(format, &i, &flg, &mod);
			if (checker == 0)
				count += print_unknown(flg, format[i]);
			if (checker == -1)
				return (-1);
			if (checker == 1)
			{
				f = spec_func(format[i]);
				value = f(args, flg, mod);
				count += value;
			}
		}
	}
	va_end(args);
	return (count);
}
