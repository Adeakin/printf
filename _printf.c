#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "func.h"
/**
 * _printf - Printf function
 * @format: format
 *
 * Return: the number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int spec_char = 0, n = 0;
	va_list args_list;

	if (format == NULL)
		return (-1);

	va_start(args_list, format);
	while (format[n] != '\0')
	{
		if (format[n] == '%' && format[n + 1] == 'c')
		{
			spec_char += prinTf(args_list);
			n += 2;
		}
		else if (format[n] == '%' && format[n + 1] == 's')
		{
			spec_char += _prinTf(args_list);
			n += 2;
		}
		else if (format[n] == '%' && format[n + 1] == 'd')
		{
			spec_char += convert(args_list);
			n += 2;
		}
		else if (format[n] == '%' && format[n + 1] == 'i')
		{
			spec_char += convert(args_list);
			n += 2;
		}
		else if (format[n] == '%' && format[n + 1] == 'b')
		{
			unsigned int num = va_arg(args_list, unsigned int);
			char *binary = print_bin(num);
			spec_char +=  _print_bin(binary);
			free(binary);
			n += 2;
		}
		else
		{
			_putchar(format[n]);
			spec_char++;
			n++;
		}
	}
	va_end(args_list);
	return (spec_char);
}
