#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "funcs.h"

/**
 * to_print_bin - converts int to octal
 * @num: input int
 * @s: The buffer to store the octal string
 * Return: octal value as an int
 */
char *to_print_bin(va_list args_list)
{
	int x = 0, j;
	char *s;
	unsigned int n = va_arg(args_list, unsigned int);

	s = malloc(12 * sizeof(char));
	if (s == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (n == 0)
	{
		s[x++] = '0';
	}
	else
	{
		while (n != 0)
		{
			s[x++] = (n % 8) + '0';
			n /= 8;
		}
	}
	s[x] = '\0';
	for (j = 0; j < x / 2; j++)
	{
		char tmp = s[j];
		s[j] = s[x - j - 1];
		s[x - j - 1] = tmp;
	}
	return (s);
}
/**
 * _print_bin - Prints an integer to stdout
 * @arg_list: List of arguments from va_start
 * Return: The number of characters printed
 */
int _print_bin(va_list args_list)
{
	char *str_ptr = int_to_oct(args_list);
	int len = 0;
	while (str_ptr && *str_ptr)
	{
		_putchar(*str_ptr++);
		len++;
	}
	free(str_ptr - len);
	return (len);
}
