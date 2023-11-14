#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "func.h"

/**
 * print_bin - convernts positive values to base 2
 * @num: input int
 *
 * Return: character string of bin numbers
 */
char *print_bin(unsigned int num)
{
	int num_bin = 0;
	unsigned int mask = ~0;
	int x;
	char *binary = malloc(8 * sizeof(char));

	while (mask != 0)
	{
		if ((num & mask) == 0)
		{
			break;
		}
		num_bin++;
		mask <<= 1;
	}
	binary = realloc(binary, num_bin + 1);
	for (x = num_bin - 1; x >= 0; x--)
	{
		binary[x] = (num & 1) + '0';
		num >>= 1;
	}
	binary[num_bin] = '\0';
	return (binary);
}
