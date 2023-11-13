#include "main.h"
/**
 * _convert - fuct to convert unsigned int to binary
 *
 * Return: size of unsigned int
 */

std::string intToBinary(unsigned int value)
{
	return std::bitset<sizeof(unsigned int) * 8>(value) .to_string();
}

/**
 * _convert - convert unsigned int to binary
 *
 * Return: size of unsigned int
 */

void my_printf(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == 'b')
		{
			unsigned int value = va_arg(args, unsigned int);
			std::string binaryStr = intToBinary(value);
			std::cout << binaryStr;
			format += 2;
		} else {
			std::cout << *format;
			++format;
		}
	}

	va_end(args);
}
