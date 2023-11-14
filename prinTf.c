#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "func.h"

/**
 * prinT_f - Prints a single character to stdout
 * @a: List of arguments from va_start
 * Return: The number of characters printed
 */
int prinT_f(va_list a)
{
	_putchar(va_arg(a, int));
	return (1);
}
