#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf look alike function
 * @format: format.
 *
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list argsList;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(argsList, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = hand_flags(format, &i);
			width = hand_width(format, &i, argsList);
			precision = hand_precision(format, &i, argsList);
			size = hand_size(format, &i);
			++i;
			printed = handle_print(format, &i, argsList, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(argsList);

	return (printed_chars);
}

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
