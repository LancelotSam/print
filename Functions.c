#include <unistd.h> /*For the write & putchar*/
#include "main.h"
/**PRINT BUFFER*/
/**
 * print_buff-this is the main function
 * It reduces the need to call write
 * @buffer:to store the input and output desired value
 * @buff_ind-a pointer to the start position of buffer
 * Return:void
 */
void print_buff(char buffer[], int *buff_ind)
{
        if (*buff_ind > 0)
                write(1, &buffer[0], *buffer_ind);
        *buff_ind = 0; /*resets it for the next use*/
}

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
