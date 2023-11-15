#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Format string containing the arguments
 * @ind: Current index in the format string
 * @argsList: List of arguments to be printed
 * @buffer: Buffer array to handle printing
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed or -1 for error
 */
int handle_print(const char *fmt, int *ind, va_list argsList, char buffer[], 
		int flags, int width, int precision, int size)
{
	int c, unknownLen = 0, printedChars = -1;
	
	/** Format types and their corresponding print functions */
	fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_string}, {'\0', NULL}
	};
	for (c = 0; fmt_types[c].fmt != '\0'; c++)
	{
		if (fmt[*ind] == fmt_types[c].fmt)
		{
			return fmt_types[c].fn(argsList, buffer, flags, width, precision, size);
		}
	}
	/** Handle unknown format specifier */
	if (fmt_types[c].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
		{
			return -1;
		}
		/** Print %% */
		unknownLen += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
		{
			unknownLen += write(1, " ", 1);
		}
		else if (width)
		{
			/** Adjust index to handle width specifier */
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			{
				--(*ind);
			}
			
			if (fmt[*ind] == ' ')
			{
				--(*ind);
			}
			return 1;
		}
		/** Print the character after % */
		unknownLen += write(1, &fmt[*ind], 1);
		return unknownLen;
	}
	return printedChars;
}
