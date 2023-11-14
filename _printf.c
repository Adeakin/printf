#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

/**
 * _printf - Printf function
 *
 * Return: the number of characters printed 
 */
int _printf(const char *format, ...)
{
	int spec_char = 0;
	va_list args_list;

	if (format == NULL)
		return (-1);

	va_start(args_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					putchar(va_arg(args_list, int));
					spec_char++;
					break;
				case 's':
					puts(va_arg(args_list, char *));
					spec_char++;
					break;
				default:
					putchar(*format);
					spec_char++;
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args_list);
	return (spec_char);
}
