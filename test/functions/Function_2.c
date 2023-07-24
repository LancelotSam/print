#include "main.h"
*
* It produces output according to a format.
* @format: The format from input.
* Return: The number of characters printed.
	*/
int _printf(const char *format, ...)
{
	va_list ap;
	int n = 0;

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			/*%-conversion specifier */
			format++;
			if (*format == '%')
			{
				/* %%-conversion specifier */
				n += my_putchar('%');
			}
			else if (*format == 'd' || *format == 'i')
			{
				/* Integer conversion (%d or %i) */
				int i = va_arg(ap, int);
				n += print_integer(i);
			}
			else if (*format == 'f')
			{
				/* Floating point conversion */
				double f = va_arg(ap, double);
				n += printf("%f", f);
			}
			else if (*format == 'c')
			{
				/* Character conversion */
				char c = (char)va_arg(ap, int);
				n += my_putchar(c);
			}
			else
			{
				/* Unknown conversion specifier */
				n += my_putchar('%');
				n += my_putchar(*format);
			}
		}
		else
		{
			/* Ordinary characters */
			n += my_putchar(*format);
		}
		format++;
	}

	va_end(ap);

	return (n);
}

