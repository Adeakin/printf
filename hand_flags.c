#include "funcs.h"

/**
 * hand_flags - Calculate active flags
 * @format: Format string in the arguments
 * @i: Current position in the format string
 * 
 * Return: Active flags
 */
int hand_flags(const char *format, int *c)
{
	/** Flags characters and their corresponding values **/
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	
	int flags = 0;
	int cIndex;
	
	/** check through characters after '%' to find flags **/
	for (cIndex = *c + 1; format[cIndex] != '\0'; cIndex++)
	{
		int x;
		
		for (x = 0; FLAGS_CH[x] != '\0'; x++)
		{
			if (format[cIndex] == FLAGS_CH[x])
			{
				flags |= FLAGS_ARR[x];
				break;
			}
		}
		
		if (FLAGS_CH[x] == '\0')
			break;
	}

	/** Update the index to the last processed position **/
	*c = cIndex - 1;
	
	return flags;
}

