#include <unistd.h>

/**
 * my_putchar-this is the main function
 *
 * It handles individual characters
 * @c:the character to be put
 * Return: integer with the address of the address of c
 */
int my_putchar(char c)
{
	return write(1, &c, 1);/*Writes the character to stdio*/
}
