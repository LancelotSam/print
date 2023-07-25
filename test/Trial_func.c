#include <unistd.h>
#include "main.h"
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
	return write(1, &c, 1);/*Writes the character to stdio*/
}
