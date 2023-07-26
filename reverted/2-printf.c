#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
/**
 * print_integer-this is the main function
 *
 * It prints an integer
 * @value: the value of the input
 * Return:an integer
 */
int print_int(int value)
{
	char buffer[BUFF_SIZE];
	int neg = 0 ,digits = 0 , i = 0;
	int temp;
	char reverse_buffer[BUFF_SIZE];

	if (value == 0)
	{
		buffer[digits++] = '0';
	}
	else
	{
		if (value < 0)
		{
			neg = 1;
			value = -value;
		}
	}
	temp = value;

	while (temp)
	{/*convert integer to a reversed string*/
		buffer[digits++] = '0' + (temp % 10);
		temp /= 10;
	}
	if (neg)
	{
		buffer[digits++] = '-';
	}
	buffer[digits] = '\0';
	for (i = 0;i < digits; i++)
	{
		reverse_buffer[i] = buffer[digits - i - 1];
		write(1, &reverse_buffer[i], 1);
	}
	return (digits);
}
/**
 * _putchar-this is the main function
 *
 * It handles individual characters
 * @c:the character to be put
 * Return: integer with the address of the address of c
 */
int _putchar(char c)
{
	return (write(1, &c, 1));/*Writes the character to stdio*/
}

/**
 * print_pointer-this is the main function
 *
 * It prints the address of a pointer
 * @format:this is the last argument
 * @...:this is the list of variable arguments
 * Return:void
 */
void print_pointer(const char *format, ...)
{
	/*char buffer[BUFF_SIZE];unused snce print is by character*/
	void *pointer;
	va_list arg;
	int i, num_hex_digits, extract_dig;
	uintptr_t ptr_val;

	va_start(arg, format);
	pointer = va_arg(arg, void *);
	/**
	 * casting the pointer to an unsigned integer (uintptr)
	 * converts void pointer to int for putchaar
	 */
	ptr_val = (uintptr_t)pointer;
	/*calc hexa vals required for pointer*/
	num_hex_digits = sizeof(uintptr_t) * 2;
	putchar('0');
	putchar('x');
	/*buff_len = snprintf(buffer, sizeof(buffer), "%p", pointer);*/
	for (i = num_hex_digits - 1; i >= 0; i--)
	{
		extract_dig = (ptr_val >> (i * 4)) & 0xF; /*shifting each digit by its size*/
		putchar(HEX_DIGITS[extract_dig]);
	}
	putchar('\n');
	/*write(1, buffer, buff_len);*/
	/*_putchar not allowed because it is nested*/
	va_end(arg);
}

/**
 * print_buff-this is the main function
 * It reduces the need to call write
 * @buffer:to store the input and output desired value
 * @buff_ind:a pointer to the start position of buffer
 * Return:void
 */
void print_buff(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0; /*resets it for the next use*/
}

/**
 * _printf - this is the main function
 * It produces output according to a format.
 * @format: Parameter is a character string
 * @...: variety of arguments
 * Return: Always number of characters printed (success)

 int _printf(const char *format, ...)
 {
 int count, c, num;
 char *str;
 va_list arg;
 void *ptr;

 va_start(arg, format);
 while (*format)
 {
 if (*format != '%')
 {
 _putchar(*format);
 count++;
 }
 else
 {
 format++;
 switch (*format)
 {
 case 'c':
 c = va_arg(arg, int);
 _putchar(c);
 count++;
 break;
 case 's':
 str = va_arg(arg, char*);
 while (*str)
 {
 _putchar(*str);
 str++;
 count++;
 }
 break;
 case 'd':
 case 'i':
 num = va_arg(arg, int);
 print_integer(num);
 count++;
 break;
 case 'p':
 ptr = va_arg(arg, void *);
 print_pointer(ptr);
 count++;
 break;
 case '%':
 _putchar('%');
 count++;
 break;
 default:
 _putchar('%');
 _putchar(*format);
 count++;
 }
 }
 format++;
 }
 va_end(arg);
 return (count);
 }

 int _printf(const char *format, ...)
 {
 va_list ap;
int counter = 0, printd = 0, buff_index = 0;
int value;
int c;
void *ptr;
char buffer[BUFF_SIZE];*defined in macro*/
/**
 *
 va_start(ap, format);

 while (*format)
 {
 if (*format == '%')  start of a conversion specifiers*/
/*{
  format++; *next character after '%'*/

/*			if (*format == '%') * '%%' */
/*			{
			buffer[buff_index++] = '%';
			if (buff_index == BUFF_SIZE)
			{
			print_buff(buffer, &buff_index);
			counter += buff_index;
			}
			}
			else if (*format == 'c') * '%c' */
/*{
  c = va_arg(ap, int);
  buffer[buff_index++] = c;
  if (buff_index == BUFF_SIZE)
  {
  print_buff(buffer, &buff_index);
  counter += buff_index;
  }
  }
  else if (*format == 's') * '%s'*/
/*	{
	char *str = va_arg(ap, char *);
	while (*str) * Iterate through the string*/
/*		{
		buffer[buff_index++] = *str;
		str++;
		if (buff_index == BUFF_SIZE)
		{
		print_buff(buffer, &buff_index);
		counter += buff_index;
		}
		}
		}
		else if (*format == 'd' || *format == 'i') *'%d' or '%i'*/
/*	{
	value = va_arg(ap, int);
	printd = print_int(value);
	counter += printd;
	}
	else if (*format == 'p') * '%p'*/
/*	{
	ptr = va_arg(ap, void *);
	print_pointer(ptr);
	counter++;
	}
	else *For Regular characters not needing conversion specifiers*/
/*	{
	buffer[buff_index++] = *format;
	if (buff_index == BUFF_SIZE)
	{
	print_buff(buffer, &buff_index);
	counter += buff_index;
	}
	}

	format++; *next character in the format string*/
/*	}
	print_buff(buffer, &buff_index);
	counter += buff_index;
	}
	va_end(ap); * Clears argument list*/
/*
   return (counter);  returns printed chars
   }
   */
int _printf(const char *format, ...) {
	va_list ap;
	int counter = 0, buff_index = 0;
	int value;
	int c;
	int printd;
	void *ptr;
	char buffer[BUFF_SIZE];

	va_start(ap, format);

	while (*format) {
		if (*format == '%') {
			format++; /* Move past '%' */

			if (*format == '%') {
				buffer[buff_index++] = '%';
			} else if (*format == 'c') {
				c = va_arg(ap, int);
				buffer[buff_index++] = c;
			} else if (*format == 's') {
				char *str = va_arg(ap, char *);
				while (*str) {
					buffer[buff_index++] = *str;
					str++;
				}
			} else if (*format == 'd' || *format == 'i') {
				value = va_arg(ap, int);
				printd = print_int(value);
				counter += printd;
			} else if (*format == 'p') {
				ptr = va_arg(ap, void *);
				print_pointer(ptr);
			} else {
				buffer[buff_index++] = *format;
			}

			format++; /* Move to the next character after the conversion specifier */

			if (buff_index == BUFF_SIZE) {
				print_buff(buffer, &buff_index);
				counter += buff_index;
			}
		} else {
			buffer[buff_index++] = *format;

			if (buff_index == BUFF_SIZE) {
				print_buff(buffer, &buff_index);
				counter += buff_index;
			}

			format++; /* Move to the next character in the format string */
		}
	}

	/* Print any remaining characters in the buffer*/
	print_buff(buffer, &buff_index);
	counter += buff_index;

	va_end(ap); /* Clears argument list */

	return (counter); /* Return the total number of printed characters */
}

