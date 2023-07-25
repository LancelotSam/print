#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - this is the main function
 * It produces output according to a format.
 * @format: Parameter is a character string
 * @...: variety of arguments
 * Return: Always number of characters printed (success)
 */
int _printf(const char *format, ...)
{
	int count, c, num;
	char *str;
	va_list arg;

	va_start(arg, format);
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(arg, int);
					putchar(c);
					count++;
					break;
				case 's':
					str = va_arg(arg, char*);
					while (*str)
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				case 'd':
				case 'i':
				case '%':
					num = va_arg(arg, int);
					print_integer(num);
					count++;
			}
					break;
					putchar('%');
					count++;
					break;
		}
		format++;
	}
	va_end(arg);
	return (count);
}
