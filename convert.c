#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "func.h"

/**
 * convert_int - Prints an integer to stdout
 * @arg_list: List of arguments from va_start
 * Return: The number of characters printed
 */
int convert_int(va_list args_list)
{
	char *str;
	int x, len, y;

	x = va_arg(args_list, int);
	str = malloc(12 * sizeof(char));
	if (str == NULL)
	{
		exit(EXIT_FAILURE);
	}
	/*str[_strlen(str)] = '\0';*/
	int_to_str(x, str);
	len = _strlen(str);
	y = 0;
	while (y < len)
	{
		_putchar(str[y]);
		y++;
	}
	free(str);
	return (len);
}
