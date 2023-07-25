#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>/*for malloc*/
#include <stdarg.h>/*for variadic functions*/

#define BUFF_SIZE 1024/*where write output is to be stored*/

int _printf(const char *format, ...);
void print_buff(char buffer[], int *buff_ind);
int _putchar(char c);


#endif /* MAIN_H */
