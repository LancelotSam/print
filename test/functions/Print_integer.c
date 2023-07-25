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

	if (value == 0)
		buffer[digits++] = '0';
	else
	{
		if (value < 0)
		{
			neg = 1;
			value = -value;
		}
	}
	int temp = value;

	while (temp)
	{/*convert integer to a reversed string*/
		buffer[digits++] = '0' + (temp % 10);
		temp /= 10;
		/**
		 * Reverse the digits in the buffer to get the correct order
		 *for (i = 0; i < digits / 2; i++)
		 *{
		 *char temp = buffer[i];
		 *buffer[i] = buffer[digits - i - 1];
		 *buffer[digits - i - 1] = temp;
		 *}
		 */
		for (i = digits - 1; i >= 0; i--)
		{
			write(1, &buffer[i], 1);
		}

	}

	return (digits);
}

