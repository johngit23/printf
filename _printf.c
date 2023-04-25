#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

int count = 0;
for (const char *p = format; *p != '\0'; p++)
  {
     if (*p != '%')
     {
	putchar(*p);
	count++;
	continue++;
     }
     p++;
     switch (*p)
     {
	case 'c' :
         {
 	   char c = va_arg(args, int);
	   putchar(c);
	   count++;
	   break;
         }
	case 's':
	{
	  char *s = va_arg(args, char *);
	  for (char *c = s; *c != '\0'; c++)
	  {
	    putchar (*c);
	    count++;
	  }
	  break;
	}
	case '%' : 
	 {
	   putchar('%');
	   count++;
	   break;
	 }
	default:
	   break;
 
     }  

  }
  va_end(args);
  return count;
}
