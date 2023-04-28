#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * print_number - prints an integer
 * @n: integer to print
 * Return: number of digits printed
 */
int print_number(int n)
{
    int digits = 0;

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }
    else if (n < 0)
    {
        _putchar('-');
        n = -n;
        digits++;
    }

    while (n != 0)
    {
        int digit = n % 10;
        _putchar(digit + '0');
        n /= 10;
        digits++;
    }

    return (digits);
}

/**
 * _printf - prints a formatted string to the standard output
 * @format: string containing format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++; /* skip the % character */

            /* handle format specifier */
            switch (format[i])
            {
                case 'd':
                case 'i':
                    count += print_number(va_arg(args, int));
                    break;
                default:
                    _putchar('%');
                    _putchar(format[i]);
                    count += 2;
                    break;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
    }

    va_end(args);

    return (count);
}
