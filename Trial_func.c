#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdint.h>
/**
 * print_integer-this is the main function
 *
 * It prints an integer
 * @value: the value of the input
 * Return:an integer
 */
int print_integer(int value)
{
	char buffer[BUFF_SIZE];
	int neg = 0;
	int digits = 0;
	int i = 0;
	int temp;

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
	for (i = digits - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
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
	/*buff_len = snprintf(buffer, sizeof(buffer), "%p", pointer);*/
	for (i = num_hex_digits - 1; i >= 0; i--)
	{
		extract_dig = (ptr_val >> (i * 4)) & 0xF; /*shifting each digit by its size*/
		putchar(HEX_DIGITS[extract_dig]);
	}
	/*write(1, buffer, buff_len);*/
	/*_putchar not allowed because it is nested*/
	putchar('\n');
	va_end(arg);
}
