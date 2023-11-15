#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _printf - Printf look alike function
 * @format: input format
 *
 * Return: characters printed 
 */
int _printf(const char *format, ...)
{
	int spec_char = 0;
	va_list argslist;

	if (format == NULL)
		return (-1);

	va_start(argslist, format);
	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					putchar(va_arg(argslist, int));
					spec_char++;
					break;
				case 's':
					puts(va_arg(argslist, char *));
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
	va_end(argslist);
	return (spec_char);
}
