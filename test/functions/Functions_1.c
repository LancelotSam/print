#include <unistd.h> /*For the write function*/
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

/*PRINT THE STRING */

