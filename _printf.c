#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * funcs -  function prototypes
 */
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf- Printf lookalike function
 * @format: input format
 *
 * Return: the number of characters formatted and printed
 */

int _printf(const char *format, ...)
{
	/**
	 * declaration of variable
	 */
	int c, printed, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list argsList;
	char buffer[BUFF_SIZE];
	
	/* NULL format check */
	if (format == NULL)
		return (-1);
	
	va_start(argsList, format);
	
	for (c = 0; format && format[c] != '\0'; c++)
	{
		if (format[c] != '%')
		{
			buffer[buff_ind++] = format[c];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			/* Processing the format specifier */
			print_buffer(buffer, &buff_ind);
			flags = hand_flags(format, &c);
			width = hand_width(format, &c, argsList);
			precision = hand_precision(format, &c, argsList);
			size = hand_size(format, &c);
			++c;
			printed = handle_print(format, &c, argsList, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(argsList);
	return (printed_chars);
}

/* Prints the contents of the buffer only if it exists */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	
	*buff_ind = 0;
}
