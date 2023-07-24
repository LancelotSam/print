/************************* STRING LENGTH *************************/
/**
 * _strlen-this is the main function
 *
 * it calculates the length of a string
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * Return: Number of chars printed
 */
int print_string(va_list types, char *)
{
	int length = 0;
	char *str = va_arg(types, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[length] != '\0')
		length++;

	return (str);
}
