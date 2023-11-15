#include "main.h"

/**
 * hand_size - Determines the size modifier for casting the argument
 * @format: Format string containing the arguments
 * @c: Current position in the format string
 * 
 * Return: Size modifier
 */
int hand_size(const char *format, int *c)
{
	int cIndex = *c + 1;
	int size = 0;
	
	if (format[cIndex] == 'l')
	{
		size = S_LONG;
	}
	else if (format[cIndex] == 'h')
	{
		size = S_SHORT;
	}
	
	if (size == 0)
	{
		*c = cIndex - 1;
	}
	else
	{
		*c = cIndex;
	}
	
	return size;
}

