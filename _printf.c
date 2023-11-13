#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _printf - Printf function
 * @format: format
 *
 * Return: the number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int spec_char = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					putchar(va_arg(args, int));
					spec_char++;
					break;
				case 's':
					spec_char += fputs(va_arg(args, char *), stdout);
					break;
				case '%':
					putchar('%');
					spec_char++;
					break;
				default: 
					putchar(*format);
					spec_char++;
			}
		}
		else
		{
			putchar (*format);
		}
		format++;
	}
	va_end(args);
	return (spec_char);
}
