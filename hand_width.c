#include "main.h"

/**
 * hand_width - Extracts the width for printing from the format string
 * @format: Format string containing the arguments
 * @c: Argument to be printed
 * @argsList: List of arguments
 * 
 * Return: Extracted width
 */
int hand_width(const char *format, int *c, va_list argsList)
{
	int cIndex;
	int width = 0;
	
	for (cIndex = *c + 1; format[cIndex] != '\0'; cIndex++)
	{
		if (is_digit(format[cIndex]))
		{
			width *= 10;
			width += format[cIndex] - '0';
		}
		else if (format[cIndex] == '*')
		{
			cIndex++;
			width = va_arg(argsList, int);
			break;
		}
		else
		{
			break;
		}
	}

	/** Update the index to the last processed position **/
	*c = cIndex - 1;
	
	return width;
}

