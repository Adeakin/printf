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
	va_list lead_list;

	if (format == NULL)
		return (-1);

	va_start(lead_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					putchar(va_arg(lead_list, int));
					spec_char++;
					break;
				case 's':
					spec_char += fputs(va_arg(lead_list, char *), stdout);
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
	va_end(lead_list);
	return (spec_char);
}
