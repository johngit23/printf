#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*ptr_func)(va_list, flags_t *);
	const char *ptr;
	va_list list;
	flags_t flags = {0, 0, 0};
	int count = 0;

	va_start(list, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;

			if (*ptr == '%')
			{
				count += _print_char('%');
				continue;
			}

			while (set_flag(*ptr, &flags))
				ptr++;
			ptr_func = get_print(*ptr);

			if (!ptr_func)
				count += _printf("%%%c", *ptr);
			else
				count += ptr_func(list, &flags);
		}
		else
			count += _print_char(*ptr);
	}
	_print_char(-1);
	va_end(list);
	return (count);
}
