#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>/*for malloc*/
#include <stdarg.h>/*for variadic functions*/

#define BUFF_SIZE 1024/*where write output is to be stored*/
#define HEX_DIGITS "0123456789abcdef"

int _printf(const char *format, ...);
int _putchar(char c);
void print_buff(char buffer[], int *buff_ind);
int print_integer(int value);
void print_pointer(const char *format, ...);

#endif
