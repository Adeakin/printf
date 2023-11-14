#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "func.h"

/**
 * _prinT_f - Prints a string to stdout
 * @s: List of arguments from va_start
 * Return: The number of characters printed
 */
int _prinT_f(va_list s)
{
	char *arg_str = va_arg(s, char *);
	int len_s = 0;

	while (arg_str && *arg_str)
	{
		_putchar(*arg_str++);
		len_s++;
	}
	return (len_s);
}
