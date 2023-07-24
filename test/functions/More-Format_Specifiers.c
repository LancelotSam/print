#include "main.h"
/*Conversion Specifers unsigned int u, unsigned hexa x lower,
 *  unsigned hexa X upper, and unsigned octal o*/
/**
 * _printf-this is the main function
 *
 * it prints output according to conversion specifiers
 * @format:the user input format
 * Return: integer
 */
int _printf(const char *format, ...)
{
        va_list args;
        int counter = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == %)
			format++;
		{
			if (*format == 'u')
				unsigned int val = va_args(args, unsigned int);
			write(1, &val, sizeof(val));
			if (*format == 'x')
				unsigned hex = va_args(args, unsigned hex);
			write(1, &hex, sizeof(hex));
			if (*format == 'X')
				unsigned HEX = va_args(args, unsigned HEX);
			write(1, &HEX, sizeof(HEX));
			if (*format == 'o')
				unsigned octal = va_args(args, unsigned octal)
					write(1, &HEX, sizeof(HEX));

