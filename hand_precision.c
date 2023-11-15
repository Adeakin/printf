#include "main.h"

/**
 * hand_precision - Extracts the precision for printing from the format string
 * @format: Format string containing the arguments
 * @c: Current position in the format string
 * @argsList: List of arguments
 * 
 * Return: Extracted precision
 */
int hand_precision(const char *format, int *c, va_list argsList)
{
	int cIndex = *c + 1;
	int precision = -1;
	
	/** precision is specified (indicated by '.') **/
	if (format[cIndex] != '.')
		return precision;
	
	precision = 0;
	
	for (cIndex += 1; format[cIndex] != '\0'; cIndex++)
	{
		if (format[cIndex])
		{
			precision *= 10;
			precision += format[cIndex] - '0';
		}
		else if (format[cIndex] == '*')
		{
			cIndex++;
			/** Get precision from the argument list **/
			precision = va_arg(argsList, int);
			break;
		}
		else
		{
			break;
		}
	}
	
	/** Update the index to the last processed position **/
	*c = cIndex - 1;
	
	return precision;
}
