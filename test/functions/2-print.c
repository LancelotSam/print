#include "main.h"
#include <stdio.h>
#include <stdarg.h>
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
int count;
int c;
char *str;
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
putchar(*format);
count++;
}
else
{
format++;
switch (*format)
{
        case 'c':
c = va_arg(arg, int);
putchar(c);
count++;
break;
case 's':
str = va_arg(arg, char*);
while (*str)
{
putchar(*str);
str++;
count++;
}
break;
case 'd':
case 'i':
case '%':
num = va_arg(arg, int);
if (num < 0)
{
putchar('-');
count++;
num = -num;
}
digits = 0;
temp = num;
do
{
temp /= 10;
digits++;
}
while (temp);
for (i = digits - 1; i >= 0; i--)
{
divisor = 1;
for (j = 0; j < i; j++)
{
divisor *= 10;
}
digit = num / divisor;
putchar('0' + digit);
count++;
num -= digit * divisor;
}
break;
putchar('%');
count++;
break;
default:
break;
}
}
format++;
}
va_end(arg);
return count;
}
