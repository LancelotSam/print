#include "main.h"
/**
 * _printf-this is the main function
 *
 * It produces output according to a format
 * @format: the format from input
 * Return: integer output
 */
int _printf(const char *format, ...)
{
	char *c;
	char *str;
	va_list ap;
	int counter = 0;

	va_start(ap, format);
	while (*format != '0') 
	{
		if (*format == '%') 
		{
			/* Handle %-conversion specifier*/
			format++;
			if (*format == 'd' || 'i') 
			{
				/* integer conversion*/
				int i = va_arg(ap, int);
				write(1, &i, sizeof(i));
				/*alternatively:print_buff(buffer, &buff_ind);*/
			} else if (*format == 'f') 
			{
				/* floating point conversion*/
				double f = va_arg(ap, double);
				write(1, &f, sizeof(f));
			}else if (*format == 's')
			{	/*handle string*/
				char *str = va_arg(ap, char*);/*holds the string*/
				while (str[counter] != '\0')/* while(*str)*/
					my_putchar(*str);/*deref the str*/
					counter++;
			} else if (*format == 'c') 
			{/*access the variables stored in c*/
				/*handle character*/
				char c = va_arg(ap, int);
				my_putchar('c');
				counter++;
			} else if (*format == '%') 
			{
				/* %%-percentage specifier*/
				my_putchar('%');
				format++;
			} 
		} else 
		{
			/* ordinary characters */
			my_putchar(*format);
			counter++;
		}
		format++;
	}
	return (counter);
}
