#include <stdio.h>
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
	int i = 0;

	va_start(ap, format);
	while (*format != '\0') 
	{
		if (*format == '%') 
		{	/* Handle %-conversion specifier*/
			format++;
			if (*format == %)
				my_putchar('%');
			counter++;
			else if (*format == 'd' || *format == 'i') 
			{	/* integer conversion*/
				int i = va_arg(ap, int);
				if (num < 0)
					my_putchar('-');
				num = -num;
				for (i = 0; i < 10; i++)
					my_putchar('0' + i);
				/*write(1, &i, sizeof(i));*/
				/*alternatively:print_buff(buffer, &buff_ind);*/
			}else if (*format == 's')
			{	/*handle string*/
				char *str = va_arg(ap, char*);/*holds the string*/
				while (str[counter] != '\0')/* while(*str)*/
					my_putchar(*str);/*deref the str*/
				counter++;
			} else if (*format == 'c') 
			{/*access the variables stored in c*/
				/*handle character*/
				int c = va_arg(ap, int);
				my_putchar(c);
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
	va_end(ap);

	return (counter);
}
