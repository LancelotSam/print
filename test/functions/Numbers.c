#include "main.h"
/**
 * print_strings-this is the main function
 *
 * It prints separated strings
 * @separates the string
 * @n: the total number of inputs
 * Return:void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *str;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(ap, char*);
		if (str == NULL)
		printf("(nil)");
		else if (separator && i == 0)
		printf("%s", str);
		else
		printf("%s%s", separator, str);
	}
	va_end(ap);

	printf("\n");
}

int numtoBinary()
