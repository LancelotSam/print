#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * print_buff-this is the main function
 * It reduces the need to call write
 * @buffer:to store the input and output desired value
 * @buff_ind-a pointer to the start position of buffer
 * Return:void
 */
void print_buff(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0; /*resets it for the next use*/
}
/**
 * print_pointer-this is the main function
 *
 * It prints the address of a pointer
 * @pointer:this is the last argument
 * @...:this is the list of variable arguments
 * Return:void
 */
void print_pointer(void *pointer, ...)
{
	/*char buffer[BUFF_SIZE];unused snce print is by character*/
	va_list arg;
	int i, num_hex_digits, extract_dig;
	uintptr_t ptr_val;

	va_start(arg, pointer);
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
 * _printf - this is the main function
 *
 * It produces output according to a format.
 * @format: Parameter is a character string
 * @...: variety of arguments
 * Return: Always number of characters printed (success)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	int c;
	char *str;
	void *ptr;
	int num;
	int digits;
	int temp;
	int i;
	int j;
	int digit;
	int divisor;
	va_list arg;

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
					if (num < 0)
					{
						_putchar('-');
						count++;
						num = -num;
					}
					digits = 0;
					temp = num;
					do {
						temp /= 10;
						digits++;
					} while (temp);

					for (i = digits - 1; i >= 0; i--)
					{
						divisor = 1;
						for (j = 0; j < i; j++)
						{
							divisor *= 10;
						}
						digit = num / divisor;
						_putchar('0' + digit);
						count++;
						num -= digit * divisor;
					}
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
					/* Handle unsupported conversion specifiers*/
					break;
			}
		}
		format++;
	}
	va_end(arg);
	return (count);
}

